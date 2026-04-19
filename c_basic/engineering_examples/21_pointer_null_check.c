#include <stdio.h>

void print_value(const int *value)
{
    if (value == NULL) {
        return;
    }

    printf("%d\n", *value);
}

int main(void)
{
    int x = 5;

    print_value(&x);

    return 0;
}