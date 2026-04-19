#include <stdio.h>

int main(void)
{
    char buf[32];
    FILE *fp = fopen("out.txt", "r");

    if (fp == NULL) {
        return 1;
    }

    if (fgets(buf, sizeof(buf), fp) != NULL) {
        printf("%s", buf);
    }

    fclose(fp);

    return 0;
}