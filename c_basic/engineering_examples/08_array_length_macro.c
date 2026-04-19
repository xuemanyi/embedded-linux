#include <stdio.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

int main(void)
{
    int values[] = {1, 2, 3};

    printf("%zu\n", ARRAY_SIZE(values));

    return 0;
}