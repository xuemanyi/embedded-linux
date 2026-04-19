#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b)
{
    return (*(const int *)a - *(const int *)b);
}

int main(void)
{
    int arr[] = {9, 1, 4, 2};

    qsort(arr, 4, sizeof(arr[0]), cmp_int);
    printf("%d\n", arr[0]);

    return 0;
}