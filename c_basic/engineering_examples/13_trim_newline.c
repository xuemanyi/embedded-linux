#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[32] = "hello\n";
    size_t len = strlen(buf);

    if (len > 0 && buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
    }

    printf("%s\n", buf);

    return 0;
}