#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *s = "abc:def";
    const char *p = strchr(s, ':');

    if (p != NULL) {
        printf("%c\n", *p);
    }

    return 0;
}