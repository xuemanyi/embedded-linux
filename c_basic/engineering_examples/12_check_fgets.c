#include <stdio.h>

int main(void)
{
    char buf[32];

    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        return 1;
    }

    printf("%s", buf);

    return 0;
}