#include <stdio.h>

int main(void)
{
    unsigned char buf[] = {0x12, 0x34, 0x56};
    size_t i;

    for (i = 0; i < sizeof(buf); i++) {
        printf("%02x ", buf[i]);
    }

    printf("\n");
    return 0;
}