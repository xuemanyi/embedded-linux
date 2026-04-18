#include <stdio.h>

/* Helper function to print array */
void print_array(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int arr[] = {5, 1, 4, 2, 3};
    int i, j, tmp, n = 5;

    printf("Initial array: ");
    print_array(arr, n);
    printf("\n");

    for (i = 0; i < n - 1; i++) {
        printf("=== Pass %d ===\n", i + 1);

        for (j = 0; j < n - 1 - i; j++) {

            /* Print comparison */
            printf("Compare arr[%d]=%d and arr[%d]=%d -> ",
                   j, arr[j], j + 1, arr[j + 1]);

            if (arr[j] > arr[j + 1]) {
                /* Swap */
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;

                printf("swap\n");
            } else {
                printf("no swap\n");
            }

            /* Print current array state */
            printf("Current array: ");
            print_array(arr, n);
        }

        printf("\n");
    }

    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}