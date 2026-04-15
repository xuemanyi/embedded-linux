#include "hash.h"

#include <stdlib.h>
#include <string.h>

#define HASH_MIN_BUCKETS 16U
#define HASH_DEFAULT_MAX_LOAD_FACTOR 0.75

typedef struct hash_node {
    void *key;
    void *value;
    struct hash_node *next;
} hash_node_t;

struct hash_table {
    hash_node_t **buckets;
    size_t bucket_count;
    size_t size;
    size_t rehash_count;
    hash_config_t config;
};

static size_t default_string_hash(const void *key);
static int default_string_cmp(const void *a, const void *b);
static void *default_string_dup(const void *key);
static void default_string_free(void *key);

static int is_valid_config(const hash_config_t *config);
static size_t bucket_index(const hash_table_t *table, const void *key);
static hash_node_t *hash_node_create(hash_table_t *table, const void *key, void *value);
static void hash_node_destroy(hash_table_t *table, hash_node_t *node);
static int maybe_rehash(hash_table_t *table);

static const hash_config_t g_default_string_config = {
    .initial_bucket_count = HASH_MIN_BUCKETS,
    .max_load_factor = HASH_DEFAULT_MAX_LOAD_FACTOR,
    .enable_auto_rehash = 1,
    .hash_fn = default_string_hash,
    .key_cmp_fn = default_string_cmp,
    .key_dup_fn = default_string_dup,
    .key_free_fn = default_string_free,
    .value_free_fn = NULL
};

static size_t default_string_hash(const void *key)
{
    const unsigned char *str = (const unsigned char *)key;
    size_t hash = 5381U;

    if (str == NULL) {
        return 0U;
    }

    while (*str != '\0') {
        hash = ((hash << 5) + hash) + (size_t)(*str);
        str++;
    }

    return hash;
}

static int default_string_cmp(const void *a, const void *b)
{
    if (a == NULL || b == NULL) {
        return -1;
    }

    return strcmp((const char *)a, (const char *)b);
}

static void *default_string_dup(const void *key)
{
    const char *src = (const char *)key;
    size_t len;
    char *dst;

    if (src == NULL) {
        return NULL;
    }

    len = strlen(src);
    dst = (char *)malloc(len + 1U);
    if (dst == NULL) {
        return NULL;
    }

    memcpy(dst, src, len + 1U);
    return dst;
}

static void default_string_free(void *key)
{
    free(key);
}

static int is_valid_config(const hash_config_t *config)
{
    if (config == NULL) {
        return 0;
    }

    if (config->hash_fn == NULL ||
        config->key_cmp_fn == NULL ||
        config->key_dup_fn == NULL ||
        config->key_free_fn == NULL) {
        return 0;
    }

    if (config->max_load_factor <= 0.0) {
        return 0;
    }

    return 1;
}

static size_t bucket_index(const hash_table_t *table, const void *key)
{
    return table->config.hash_fn(key) % table->bucket_count;
}

static hash_node_t *hash_node_create(hash_table_t *table, const void *key, void *value)
{
    hash_node_t *node;

    if (table == NULL || key == NULL) {
        return NULL;
    }

    node = (hash_node_t *)malloc(sizeof(*node));
    if (node == NULL) {
        return NULL;
    }

    node->key = table->config.key_dup_fn(key);
    if (node->key == NULL) {
        free(node);
        return NULL;
    }

    node->value = value;
    node->next = NULL;
    return node;
}

static void hash_node_destroy(hash_table_t *table, hash_node_t *node)
{
    if (table == NULL || node == NULL) {
        return;
    }

    if (table->config.key_free_fn != NULL) {
        table->config.key_free_fn(node->key);
    }

    if (table->config.value_free_fn != NULL && node->value != NULL) {
        table->config.value_free_fn(node->value);
    }

    free(node);
}

static int maybe_rehash(hash_table_t *table)
{
    double load_factor;

    if (table == NULL) {
        return -1;
    }

    if (!table->config.enable_auto_rehash) {
        return 0;
    }

    load_factor = (double)table->size / (double)table->bucket_count;
    if (load_factor <= table->config.max_load_factor) {
        return 0;
    }

    return hash_rehash(table, table->bucket_count * 2U);
}

hash_table_t *hash_create(const hash_config_t *config)
{
    hash_table_t *table;
    size_t bucket_count;

    if (!is_valid_config(config)) {
        return NULL;
    }

    bucket_count = config->initial_bucket_count;
    if (bucket_count < HASH_MIN_BUCKETS) {
        bucket_count = HASH_MIN_BUCKETS;
    }

    table = (hash_table_t *)malloc(sizeof(*table));
    if (table == NULL) {
        return NULL;
    }

    table->buckets = (hash_node_t **)calloc(bucket_count, sizeof(*table->buckets));
    if (table->buckets == NULL) {
        free(table);
        return NULL;
    }

    table->bucket_count = bucket_count;
    table->size = 0U;
    table->rehash_count = 0U;
    table->config = *config;

    return table;
}

void hash_destroy(hash_table_t *table)
{
    hash_node_t *node;
    hash_node_t *next;
    size_t i;

    if (table == NULL) {
        return;
    }

    for (i = 0; i < table->bucket_count; i++) {
        node = table->buckets[i];
        while (node != NULL) {
            next = node->next;
            hash_node_destroy(table, node);
            node = next;
        }
    }

    free(table->buckets);
    free(table);
}

int hash_put(hash_table_t *table, const void *key, void *value)
{
    hash_node_t *node;
    hash_node_t *new_node;
    size_t index;

    if (table == NULL || key == NULL) {
        return -1;
    }

    index = bucket_index(table, key);
    node = table->buckets[index];

    while (node != NULL) {
        if (table->config.key_cmp_fn(node->key, key) == 0) {
            if (table->config.value_free_fn != NULL && node->value != NULL) {
                table->config.value_free_fn(node->value);
            }
            node->value = value;
            return 0;
        }
        node = node->next;
    }

    new_node = hash_node_create(table, key, value);
    if (new_node == NULL) {
        return -1;
    }

    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
    table->size++;

    if (maybe_rehash(table) != 0) {
        return 0;
    }

    return 0;
}

int hash_get(const hash_table_t *table, const void *key, void **value)
{
    hash_node_t *node;
    size_t index;

    if (table == NULL || key == NULL || value == NULL) {
        return -1;
    }

    index = bucket_index(table, key);
    node = table->buckets[index];

    while (node != NULL) {
        if (table->config.key_cmp_fn(node->key, key) == 0) {
            *value = node->value;
            return 0;
        }
        node = node->next;
    }

    return -1;
}

int hash_remove(hash_table_t *table, const void *key)
{
    hash_node_t *node;
    hash_node_t *prev;
    size_t index;

    if (table == NULL || key == NULL) {
        return -1;
    }

    index = bucket_index(table, key);
    node = table->buckets[index];
    prev = NULL;

    while (node != NULL) {
        if (table->config.key_cmp_fn(node->key, key) == 0) {
            if (prev == NULL) {
                table->buckets[index] = node->next;
            } else {
                prev->next = node->next;
            }

            hash_node_destroy(table, node);
            table->size--;
            return 0;
        }

        prev = node;
        node = node->next;
    }

    return -1;
}

int hash_contains(const hash_table_t *table, const void *key)
{
    void *value;

    return hash_get(table, key, &value) == 0 ? 1 : 0;
}

size_t hash_size(const hash_table_t *table)
{
    if (table == NULL) {
        return 0U;
    }

    return table->size;
}

int hash_rehash(hash_table_t *table, size_t new_bucket_count)
{
    hash_node_t **new_buckets;
    hash_node_t *node;
    hash_node_t *next;
    size_t i;
    size_t index;

    if (table == NULL || new_bucket_count < HASH_MIN_BUCKETS) {
        return -1;
    }

    new_buckets = (hash_node_t **)calloc(new_bucket_count, sizeof(*new_buckets));
    if (new_buckets == NULL) {
        return -1;
    }

    for (i = 0; i < table->bucket_count; i++) {
        node = table->buckets[i];
        while (node != NULL) {
            next = node->next;
            index = table->config.hash_fn(node->key) % new_bucket_count;
            node->next = new_buckets[index];
            new_buckets[index] = node;
            node = next;
        }
    }

    free(table->buckets);
    table->buckets = new_buckets;
    table->bucket_count = new_bucket_count;
    table->rehash_count++;

    return 0;
}

int hash_foreach(const hash_table_t *table, hash_foreach_fn fn, void *user_data)
{
    hash_node_t *node;
    size_t i;
    int ret;

    if (table == NULL || fn == NULL) {
        return -1;
    }

    for (i = 0; i < table->bucket_count; i++) {
        node = table->buckets[i];
        while (node != NULL) {
            ret = fn(node->key, node->value, user_data);
            if (ret != 0) {
                return ret;
            }
            node = node->next;
        }
    }

    return 0;
}

int hash_get_stats(const hash_table_t *table, hash_stats_t *stats)
{
    hash_node_t *node;
    size_t i;
    size_t chain_len;
    size_t used_buckets = 0U;
    size_t collision_count = 0U;
    size_t max_chain_length = 0U;

    if (table == NULL || stats == NULL) {
        return -1;
    }

    for (i = 0; i < table->bucket_count; i++) {
        node = table->buckets[i];
        chain_len = 0U;

        while (node != NULL) {
            chain_len++;
            node = node->next;
        }

        if (chain_len > 0U) {
            used_buckets++;
        }

        if (chain_len > 1U) {
            collision_count += (chain_len - 1U);
        }

        if (chain_len > max_chain_length) {
            max_chain_length = chain_len;
        }
    }

    stats->size = table->size;
    stats->bucket_count = table->bucket_count;
    stats->used_buckets = used_buckets;
    stats->collision_count = collision_count;
    stats->max_chain_length = max_chain_length;
    stats->load_factor = (double)table->size / (double)table->bucket_count;
    stats->rehash_count = table->rehash_count;

    return 0;
}

const hash_config_t *hash_get_default_string_config(void)
{
    return &g_default_string_config;
}