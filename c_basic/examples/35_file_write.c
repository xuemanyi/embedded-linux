#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("test.txt", "w");
    if (fp == NULL) {
        return 1;
    }

    fprintf(fp, "hello file\n");
    fclose(fp);

    return 0;
}