#include <stdio.h>

int main(void)
{
    int values[] = {2, 4, 6, 8};
    size_t i;

    for (i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        printf("%d ", values[i]);
    }

    printf("\n");

    return 0;
}