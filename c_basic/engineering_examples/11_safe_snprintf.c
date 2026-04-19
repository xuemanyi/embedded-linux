#include <stdio.h>

int main(void)
{
    char buf[32];

    snprintf(buf, sizeof(buf), "id=%d", 100);
    printf("%s\n", buf);

    return 0;
}