#include <stdio.h>

static void print_int_info(const char *name, const int *ptr)
{
    if (name == NULL || ptr == NULL) {
        return;
    }

    printf("%s value: %d\n", name, *ptr);
    printf("%s address: %p\n", name, (const void *)ptr);
}

static void modify_value(int *ptr, int new_value)
{
    if (ptr == NULL) {
        return;
    }

    *ptr = new_value;
}

static void swap_init(int *a, int *b)
{
    int temp;

    if (a == NULL || b == NULL) {
        return;
    }

    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int a = 10;
    int b = 20;
    int *p = NULL;

    p = &a;

    printf("Initial state\n");
    print_int_info("a", &a);
    print_int_info("b", &b);

    printf("\nPointer state\n");
    printf("p stores  : %p\n", (void *)p);
    printf("p reads   : %d\n", *p);

    printf("\nModify a through p\n");
    modify_value(p, 100);
    print_int_info("a", &a);
    printf("p still stores : %p\n", (void *)p);
    printf("*p now reads   : %d\n", *p);

    printf("\nSwap a and b\n");
    swap_init(&a, &b);
    print_int_info("a", &a);
    print_int_info("b", &b);

    return 0;
}