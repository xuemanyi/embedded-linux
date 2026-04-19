#include <stdio.h>

int main(void)
{
    int ch;
    FILE *fp = fopen("out.txt", "r");

    if (fp == NULL) {
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);

    return 0;
}