#include <stdio.h>
#include <string.h>

int main(void)
{
    char src[] = "hello";
    char dst[10];

    memcpy(dst, src, sizeof(src));
    printf("%s\n", dst);

    return 0;
}