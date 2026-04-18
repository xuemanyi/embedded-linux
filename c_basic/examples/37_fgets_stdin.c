#include <stdio.h>

int main(void)
{
    char buf[128];

    printf("Input: ");
    if (fgets(buf, sizeof(buf), stdin) != NULL) {
        printf("You typed: %s", buf);
    }

    return 0;
}