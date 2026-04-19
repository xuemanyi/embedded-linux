#include <stdio.h>

typedef struct {
    int x;
    int y;
} point_t;

int main(void)
{
    point_t p = {3, 4};

    printf("%d %d\n", p.x, p.y);

    return 0;
}