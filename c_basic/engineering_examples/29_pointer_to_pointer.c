#include <stdio.h>

int main(void)
{
    int value = 7;
    int *p = &value;
    int **p = &p;

    /* warning: incompatible pointer types initializing 'int *' with 
       an expression of type 'int **'; remove & [-Wincompatible-pointer-types] */
    // int *q = &p;

    printf("%d\n", *pp);

    return 0;
}