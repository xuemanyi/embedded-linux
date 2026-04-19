#include <stdio.h>

int main(void)
{
    unsigned char buf[4];

    buf[0] = 0x12;
    buf[1] = 0x34;
    buf[2] = 0x01;
    buf[3] = 0x02;

    printf("%02x %02x %02x %02x\n", buf[0], buf[1], buf[2], buf[3]);

    return 0;
}