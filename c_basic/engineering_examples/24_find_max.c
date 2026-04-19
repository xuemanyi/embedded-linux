#include <stdio.h>

int main(void)
{
    int values[] = {3, 9, 2, 7};
    size_t i;
    int max = values[0];

    for (i = 1; i < sizeof(values) / sizeof(values[0]); i++) {
        if (values[i] > max) {
            max = values[i];
        }
    }

    printf("%d\n", max);

    return 0;
}