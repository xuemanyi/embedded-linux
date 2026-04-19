#include <stdio.h>

#define REG_ERROR_MASK (1U << 3)

int main(void)
{
    unsigned int reg = 0xff;

    reg &= ~REG_ERROR_MASK;
    printf("0x%x\n", reg);

    return 0;
}