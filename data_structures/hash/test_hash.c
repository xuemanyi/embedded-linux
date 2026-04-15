#include "hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct user_info {
    int id;
    int age;
    char name[64];
} user_info_t;

static user_info_t *user_info_create(int id, int age, const char *name)
{
    user_info_t *user;

    user = (user_info_t *)malloc(sizeof(*user));
    if (user == NULL) {
        return NULL;
    }

    user->id = id;
    user->age = age;
    snprintf(user->name, sizeof(user->name), "%s", name);
    return user;
}

static void user_info_destroy(void *value)
{
    free(value);
}

static void check(int condition, const char *msg)
{
    if (!condition) {
        fprintf(stderr, "test failed: %s\n", msg);
        exit(EXIT_FAILURE);
    }
}

static int print_entry(const void *key, void *value, void *user_data)
{
    const char *name = (const char *)key;
    user_info_t *user = (user_info_t *)value;
    FILE *out = (FILE *)user_data;

    fprintf(out, "key=%s, id=%d, age=%d, name=%s\n",
            name, user->id, user->age, user->name);
    return 0;
}

static void test_basic(hash_table_t *table)
{
    void *value = NULL;
    user_info_t *user;

    check(hash_put(table, "alice", user_info_create(1, 20, "Alice")) == 0,
          "put alice");
    check(hash_put(table, "bob", user_info_create(2, 25, "Bob")) == 0,
          "put bob");
    check(hash_put(table, "carol", user_info_create(3, 30, "Carol")) == 0,
          "put carol");

    check(hash_get(table, "alice", &value) == 0, "get alice");
    user = (user_info_t *)value;
    check(user->id == 1 && user->age == 20, "alice value");

    check(hash_contains(table, "bob") == 1, "contains bob");
    check(hash_contains(table, "nobody") == 0, "contains nobody");
}

static void test_update(hash_table_t *table)
{
    void *value = NULL;
    user_info_t *user;

    check(hash_put(table, "alice", user_info_create(10, 22, "Alice-New")) == 0,
          "update alice");

    check(hash_get(table, "alice", &value) == 0, "get updated alice");
    user = (user_info_t *)value;
    check(user->id == 10, "updated alice id");
    check(user->age == 22, "updated alice age");
    check(strcmp(user->name, "Alice-New") == 0, "updated alice name");
}

static void test_remove(hash_table_t *table)
{
    check(hash_remove(table, "bob") == 0, "remove bob");
    check(hash_contains(table, "bob") == 0, "contains bob after remove");
    check(hash_remove(table, "bob") != 0, "remove bob twice");
}

static void test_rehash(hash_table_t *table)
{
    char key[64];
    int i;

    for (i = 0; i < 1000; i++) {
        snprintf(key, sizeof(key), "user_%d", i);
        check(hash_put(table, key, user_info_create(i, 18 + (i % 40), key)) == 0,
              "bulk insert");
    }

    check(hash_size(table) >= 1000, "size after bulk insert");
}

static void test_stats(hash_table_t *table)
{
    hash_stats_t stats;

    check(hash_get_stats(table, &stats) == 0, "get stats");

    printf("\nstats:\n");
    printf("size=%zu\n", stats.size);
    printf("bucket_count=%zu\n", stats.bucket_count);
    printf("used_buckets=%zu\n", stats.used_buckets);
    printf("collision_count=%zu\n", stats.collision_count);
    printf("max_chain_length=%zu\n", stats.max_chain_length);
    printf("load_factor=%.3f\n", stats.load_factor);
    printf("rehash_count=%zu\n\n", stats.rehash_count);
}

int main(void)
{
    hash_config_t config;
    hash_table_t *table;

    config = *hash_get_default_string_config();
    config.initial_bucket_count = 16;
    config.max_load_factor = 0.75;
    config.enable_auto_rehash = 1;
    config.value_free_fn = user_info_destroy;

    table = hash_create(&config);
    check(table != NULL, "hash_create");

    test_basic(table);
    test_update(table);
    test_remove(table);
    test_rehash(table);
    test_stats(table);

    printf("dump:\n");
    check(hash_foreach(table, print_entry, stdout) == 0, "foreach");

    hash_destroy(table);
    printf("\nall tests passed\n");

    return 0;
}