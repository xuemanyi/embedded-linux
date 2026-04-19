#include <stdio.h>

int main(void)
{
    int arr[] = {10, 20, 30};
    size_t i;
    int sum = 0;

    for (i = 0; i < 3; i++) {
        sum += arr[i];
    }
    printf("%.2f\n", (double) sum / 3.0);

    return 0;
}