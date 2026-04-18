#include <stdio.h>

int main(void)
{
    int arr[] = {10, 20, 30};
    int *p = arr;

    printf("%d %d %d\n", p[0], p[1], p[2]);
    
    return 0;
}