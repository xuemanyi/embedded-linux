#include <stdio.h>

int main(void)
{
    int values[] = {1, 2, 3, 4, 6};
    size_t i;
    int count = 0;

    for (i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        if ((values[i] % 2) == 0) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}