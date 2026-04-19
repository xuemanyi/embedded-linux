#include <stdio.h>

static void print_first(const int *arr)
{
    printf("%d\n", arr[0]);
}

int main(void)
{
    int arr[] = {10, 20};

    print_first(arr);

    return 0;
}