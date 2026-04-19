#include <stdio.h>

int main(void)
{
    int current_fault = 1;
    int latched_fault = 0;

    if (current_fault) {
        latched_fault = 1;
    }

    printf("%d\n", latched_fault);

    return 0;
}