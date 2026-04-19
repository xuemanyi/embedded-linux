#include <stdio.h>

static int sum_array(const int *arr, size_t n)
{
    size_t i;
    int sum = 0;

    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    return sum;
}

int main(void)
{
    int arr[] = {1, 2, 3};

    printf("%d\n", sum_array(arr, 3));

    return 0;
}