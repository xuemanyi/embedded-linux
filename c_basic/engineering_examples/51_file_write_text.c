#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("out.txt", "w");

    if (fp == NULL) {
        return 1;
    }

    fputs("hello\n", fp);
    fclose(fp);

    return 0;
}