#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr = calloc(4, sizeof(*arr));

    if (arr == NULL) {
        return 1;
    }

    printf("%d\n", arr[0]);
    free(arr);

    return 0;
} 