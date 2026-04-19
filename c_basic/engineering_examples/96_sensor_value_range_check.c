#include <stdio.h>

int main(void)
{
    int value = 55;

    if (value < 0 || value > 100) {
        printf("invalid\n");
    } else {
        printf("valid\n");
    }

    return 0;
}