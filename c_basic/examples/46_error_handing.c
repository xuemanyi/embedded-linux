#include <stdio.h>

int divide(int a, int b, int *result)
{
    if (b == 0 || result == NULL) {
        return -1;
    }

    *result = a / b;

    return 0;
}

int main(void)
{
    int result;

    if (divide(10, 2, &result) == 0) {
        printf("%d\n", result);
    } else {
        printf("error\n");
    }

    return 0;
}