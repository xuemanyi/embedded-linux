#include <stdio.h>

struct Point {
    int x;
    int y;
};

int main(void)
{
    struct Point p = {3, 4};
    struct Point *ptr = &p;

    printf("%d %d\n", ptr->x, ptr->y);

    return 0;
}