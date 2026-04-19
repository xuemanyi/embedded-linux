#include <stdio.h>

static void swap_int(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void)
{
    int a = 1;
    int b = 2;

    swap_int(&a, &b);
    printf("%d %d\n", a, b);

    return 0;
}