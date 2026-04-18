#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    int *arr = (int *)malloc(3 * sizeof(int));
    if (arr == NULL) {
        return 1;
    }

    for (i = 0; i < 3; i++) {
        arr[i] = i + 1;
    }

    arr = (int *)realloc(arr, 5 * sizeof(int));
    if (arr == NULL) {
        return 1;
    }

    arr[3] = 4;
    arr[4] = 5;

    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}