#include <stdio.h>

int main(void)
{
    int x = 10;
    int *p = &x;

    printf("x=%d, *p=%d\n", x, *p);

    return 0;
}