#include <stdio.h>
void my_strcpy(char *dst, const char *src)
{
    while (*src != '\0') {
        *dst++ = *src++;
    }

    *dst = '\0';
}

int main(void)
{
    char buf[20];

    my_strcpy(buf, "abc");
    printf("%s\n", buf);

    return 0;
}