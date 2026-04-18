#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    int *arr = (int *)malloc(5 * sizeof(int));

    if (arr == NULL) {
        return 1;
    }

    for (i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }

    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}