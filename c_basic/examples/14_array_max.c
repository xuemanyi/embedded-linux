#include <stdio.h>

int main(void)
{
    int arr[] = {3, 7, 2, 9, 5};
    int i, max = arr[0];

    for (i = 1; i < 5; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("max=%d\n", max);
    
    return 0;
}