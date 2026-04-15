#ifndef HASH_H
#define HASH_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct hash_table hash_table_t;

typedef size_t (*hash_func_t)(const void *key);
typedef int (*hash_key_cmp_t)(const void *a, const void *b);
typedef void *(*hash_key_dup_t)(const void *key);
typedef void (*hash_key_free_t)(void *key);
typedef void (*hash_value_free_t)(void *value);

typedef int (*hash_foreach_fn)(const void *key, void *value, void *user_data);

typedef struct hash_config {
    size_t initial_bucket_count;
    double max_load_factor;
    int enable_auto_rehash;

    hash_func_t hash_fn;
    hash_key_cmp_t key_cmp_fn;
    hash_key_dup_t key_dup_fn;
    hash_key_free_t key_free_fn;
    hash_value_free_t value_free_fn;
} hash_config_t;

typedef struct hash_stats {
    size_t size;
    size_t bucket_count;
    size_t used_buckets;
    size_t collision_count;
    size_t max_chain_length;
    double load_factor;
    size_t rehash_count;
} hash_stats_t;

hash_table_t *hash_create(const hash_config_t *config);
void hash_destroy(hash_table_t *table);

int hash_put(hash_table_t *table, const void *key, void *value);
int hash_get(const hash_table_t *table, const void *key, void **value);
int hash_remove(hash_table_t *table, const void *key);
int hash_contains(const hash_table_t *table, const void *key);

size_t hash_size(const hash_table_t *table);
int hash_rehash(hash_table_t *table, size_t new_bucket_count);

int hash_foreach(const hash_table_t *table, hash_foreach_fn fn, void *user_data);
int hash_get_stats(const hash_table_t *table, hash_stats_t *stats);

const hash_config_t *hash_get_default_string_config(void);

#ifdef __cplusplus
}
#endif

#endif