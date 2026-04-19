#include <stdio.h>

static int find_index(const int *arr, size_t n, int target)
{
    size_t i;

    for (i = 0; i < n; i++) {
        if (arr[i] == target) {
            return (int)i;
        }
    }

    return -1;
}

int main(void)
{
    int arr[] = {5, 7, 9};

    printf("%d\n", find_index(arr, 3, 7));
}