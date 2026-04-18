#include <stdio.h>

void counter(void)
{
    static int count = 0;

    count++;
    printf("%d\n", count);
}

int main(void)
{
    counter();
    counter();
    counter();

    return 0;
}