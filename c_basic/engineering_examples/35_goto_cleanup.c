#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ret = 1;
    FILE *fp = NULL;
    char *buf = NULL;

    fp = fopen("tmp.txt", "w");
    if (fp == NULL) {
        goto out;
    }

    buf = malloc(16);
    if (buf == NULL) {
        goto out;
    }

    fprintf(fp, "ok\n");
    ret = 0;

out:
    free(buf);
    if (fp != NULL) {
        fclose(fp);
    }

    return ret;
}