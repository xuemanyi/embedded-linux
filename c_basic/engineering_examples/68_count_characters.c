#include <stdio.h>

int main(void)
{
    const char *s = "hello";
    int count = 0;

    while (s[count] != '\0') {
        count++;
    }

    printf("%d\n", count);

    return 0;
}