#include <stdio.h>

int main(void)
{
    unsigned int reg = 0x2c;
    unsigned int field = (reg >> 2) &0x7;

    printf("%u\n", field);

    return 0;
}