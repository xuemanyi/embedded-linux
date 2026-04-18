#include <stdio.h>

#define ADD(a, b) ((a) +  (b))

int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    int (*func)(int, int) = add;

    printf("%d\n", func(2, 3));
    printf("%d\n", add(5, 5));
    printf("%d\n", ADD(10, 10));

    return 0;
}