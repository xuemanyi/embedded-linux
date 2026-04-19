#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[] = "mode=debug";
    char *eq = strchr(line, '=');

    if (eq == NULL) {
        return 1;
    }

    *eq = '\0';
    printf("key=%s value=%s\n", line, eq + 1);
    return 0;
}
