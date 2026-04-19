#include <stdio.h>

static int binary_search(const int *arr, int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main(void)
{
    int arr[] = {1, 3, 5, 7, 9};

    printf("%d\n", binary_search(arr, 5, 5));

    return 0;
}