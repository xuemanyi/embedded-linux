#include <stdio.h>
#include <stddef.h>

static void print_int_info(const char *name, const int *ptr)
{
    if (name == NULL || ptr == NULL) {
        return;
    }

    printf("%s value  : %d\n", name, *ptr);
    printf("%s address: %p\n", name, (const void *)ptr);
}

static void set_value(int *ptr, int value)
{
    if (ptr == NULL) {
        return;
    }

    *ptr = value;
}

static void swap_int(int *a, int *b)
{
    int temp;

    if (a == NULL || b == NULL) {
        return;
    }

    if (a == b) {
        return;
    }

    temp = *a;
    *a = *b;
    *b = temp;
}

static int sum_array(const int *arr, size_t len)
{
    const int *p = NULL;
    int sum = 0;
    size_t i;

    if (arr == NULL) {
        return 0;
    }

    p = arr;

    for (i = 0; i < len; ++i) {
        sum += *(p + i);
    }

    return sum;
}

static int find_max(const int *arr, size_t len, int *max_value)
{
    const int *p = NULL;
    int max;
    size_t i;

    if (arr == NULL || max_value == NULL || len ==0U) {
        return -1;
    }

    p = arr;
    max = *p;

    for (i = 1; i < len; ++i) {
        if (*(p + i) > max) {
            max = *(p + i);
        }
    }

    *max_value = max;

    return 0;
}

static void print_array(const int *arr, size_t len, const char *name)
{
    size_t i;

    if (arr == NULL || name == NULL) {
        return;
    }

    printf("%s: [", name);

    for (i = 0; i < len; ++i) {
        printf("%d", arr[i]);
        if (i + 1U < len) {
            printf(", ");
        }
    }

    printf("]\n");
}

int main(void)
{
    int a = 10;
    int b = 10;
    int *p = NULL;

    int numbers[] = {3, 7, 2, 9, 5};
    size_t numbers_len = sizeof(numbers) / sizeof(numbers[0]);

    int max_value = 0;
    int ret = 0;

    printf("=== Exercise 1: print value and address ===\n");
    p = &a;
    print_int_info("a", &a);
    printf("p stores: %p\n", (void *)p);
    printf("*p reads: %d\n", *p);

    printf("\n=== Exercise 2: modify value through pointer ===\n");
    set_value(p, 100);
    print_int_info("a", &a);

    printf("\n=== Exercise 3: swap two integers ===\n");
    print_int_info("a", &a);
    print_int_info("b", &b);
    swap_int(&a, &b);
    printf("after swap\n");
    print_int_info("a", &a);
    print_int_info("b", &b);

    printf("\n=== Exercise 4: sum array with pointer traversal ===\n");
    print_array(numbers, numbers_len, "numbers");
    printf("sum : %d\n", sum_array(numbers, numbers_len));

    printf("\n=== Exercise 5: find max value in array ===\n");
    ret = find_max(numbers, numbers_len, &max_value);
    if (ret == 0) {
        printf("max value: %d\n", max_value);
    } else {
        printf("failed to find max value");
    }

    return 0;
}