#include <stdio.h>

int main(void)
{
    unsigned int x = 0x05;  // Initial value: 0000 0101

    /* Set bit1 (force bit1 to 1) */
    /* 1U << 1 creates mask 0000 0010 */
    printf("set bit1        : 0x%x\n", x | (1U << 1));

    /* Clear bit0 (force bit0 to 0) */
    /* ~(1U << 0) creates mask 1111 1110 */
    printf("clear bit0      : 0x%x\n", x & ~(1U << 0));

    /* Toggle bit2 (flip bit2: 1->0 or 0->1) */
    /* 1U << 2 creates mask 0000 0100 */
    printf("toggle bit 2    : 0x%x\n", x ^ (1U << 2));

    return 0;
}