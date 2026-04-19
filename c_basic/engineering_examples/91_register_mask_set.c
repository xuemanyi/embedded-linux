#include <stdio.h>
#define REG_ENABLE_MASK (1U << 0)

int main(void)
{
    unsigned int reg = 0;

    reg |= REG_ENABLE_MASK;
    printf("0x%x\n", reg);

    return 0;
}