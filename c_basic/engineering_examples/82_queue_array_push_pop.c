#include <stdio.h>

int main(void)
{
    int q[4];
    int head = 0;
    int tail = 0;

    q[tail++] = 10;
    q[tail++] = 20;

    printf("%d\n", q[head++]);

    return 0;
}