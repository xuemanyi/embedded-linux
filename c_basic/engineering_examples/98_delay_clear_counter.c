#include <stdio.h>

int main(void)
{
    int fault = 0;
    int clear_count = 3;

    if (!fault) {
        clear_count--;
    }

    printf("%d\n", clear_count);

    return 0;
}