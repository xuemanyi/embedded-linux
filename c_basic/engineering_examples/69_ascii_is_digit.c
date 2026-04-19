#include <stdio.h>

static int is_digit_char(char c)
{
    return c >= '0' && c <= '9';
}

int main(void)
{
    printf("%d\n", is_digit_char('5'));

    return 0;
}