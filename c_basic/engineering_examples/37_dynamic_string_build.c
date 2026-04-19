#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *buf = malloc(32);

    if (buf == NULL) {
        return 1;
    }

    snprintf(buf, 32, "name = %s", "demo");
    printf("%s\n", buf);

    free(buf);

    return 0;
}