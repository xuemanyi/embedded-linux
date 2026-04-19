#include <stdio.h>

int main(void)
{
    unsigned int bitmap = 0;

    bitmap |= (1U << 2);
    bitmap &= ~(1u << 2);

    printf("%u\n", bitmap);
}