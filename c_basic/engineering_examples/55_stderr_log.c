#include <stdio.h>

int main(void)
{
    char str[] = "error log";
    fprintf(stderr, "error log: %s\n", str);

    return 0;
}