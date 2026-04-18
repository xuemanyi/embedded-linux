#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[10];

    memset(buf, 'A', sizeof(buf));
    printf("%c %c\n", buf[0], buf[9]);

    return 0;
}