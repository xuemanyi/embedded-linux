#include <stdio.h>

static int divide_int(int a, int b, int *out)
{
    if (b == 0 || out == NULL) {
        return -1;
    }

    *out = a / b;

    return 0;
}

int main(void)
{
    int result = 0;

    if (divide_int(8, 2, &result) == 0) {
        printf("%d\n", result);
    }

    return 0;
}