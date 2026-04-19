#include <stdio.h>
#include <string.h>

int main(void)
{
    unsigned char buf[8];

    memset(buf, 0, sizeof(buf));

    printf("%u\n", buf[0]);

    return 0;
}