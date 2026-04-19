#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *value = malloc(sizeof(*value));

    if (value == NULL) {
        return 1;
    }

    *value = 42;
    printf("%d\n", *value);

    free(value);

    return 0;
}