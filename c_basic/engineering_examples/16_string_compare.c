#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *a = "abc";
    const char *b = "abc";

    if (strcmp(a, b) == 0) {
        printf("equal\n");
    }

    return 0;
}