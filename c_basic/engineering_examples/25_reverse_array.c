#include <stdio.h>

int main(void)
{
    int values[] = {1, 2, 3, 4};
    size_t i;
    size_t n = sizeof(values) / sizeof(values[0]);

    for (i = 0; i < n / 2; i++) {
        int tmp = values[i];
        values[i] = values[n - 1 - i];
        values[n - 1 - i] = tmp;
    }

    for (i = 0; i < n; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
    return 0;
    
}