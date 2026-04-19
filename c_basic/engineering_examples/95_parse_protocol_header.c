#include <stdio.h>

int main(void)
{
    unsigned char buf[4] = {0x12, 0x34, 0x01, 0x02};

    if (buf[0] == 0x12 && buf[1] == 0x34) {
        printf("type=%u len=%u\n", buf[2], buf[3]);
    }

    return 0;
}