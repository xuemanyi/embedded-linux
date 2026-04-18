#include <stdio.h>

int main(void)
{
    const int max = 100;

    /* error: cannot assign to variable 'max' with const-qualified type 'const int' */
    // max = 10;

    printf("%d\n", max);

    return 0;
}