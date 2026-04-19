#include <stdio.h>

struct point {
    int x;
    int y;
};

int main(void)
{
    struct point p = {.y = 2, .x = 1};

    printf("%d %d\n", p.x, p.y);

    return 0;
}