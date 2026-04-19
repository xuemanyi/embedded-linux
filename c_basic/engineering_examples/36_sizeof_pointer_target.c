#include <stdio.h>

int main(void)
{
    int value = 0;
    int *p = &value;

    printf("%zu %zu\n", sizeof(p), sizeof(*p));

    return 0;
}