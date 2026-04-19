#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int stack_value = 1;
    int *heap_value = malloc(sizeof(*heap_value));

    if (heap_value == NULL) {
        return 1;
    }

    *heap_value = 2;
    printf("%d %d\n", stack_value, *heap_value);

    free(heap_value);

    return 0;
}