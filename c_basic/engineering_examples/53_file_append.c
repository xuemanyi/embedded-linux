#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("out.txt", "a");

    if (fp == NULL) {
        return 1;
    }

    fprintf(fp, "append\n");
    fclose(fp);

    return 0;
}