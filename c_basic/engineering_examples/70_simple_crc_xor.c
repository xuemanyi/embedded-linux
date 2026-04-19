#include <stdio.h>

int main(void)
{
    unsigned char data[] = {1, 2, 3, 4};
    unsigned char crc = 0;
    size_t i;

    for (i = 0; i < sizeof(data); i++) {
        crc ^= data[i];
    }
    printf("%u\n", crc);

    return 0;
}