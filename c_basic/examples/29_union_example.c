#include <stdio.h>

union Data {
    int i;
    float f;
};

int main(void)
{
    union Data d;
    
    d.i = 10;
    printf("%d\n", d.i);

    return 0;
}