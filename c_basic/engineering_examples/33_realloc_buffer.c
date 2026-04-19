#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr = malloc(2 * sizeof(*arr));
    int *tmp;

    if (arr == NULL) {
        return 1;
    }

    tmp = realloc(arr, 4 * sizeof(*arr));
    if (tmp == NULL) {
        free(arr);
        return 1;
    }

    arr = tmp;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;

    printf("%d\n", arr[3]);
    free(arr);

    return 0;
}