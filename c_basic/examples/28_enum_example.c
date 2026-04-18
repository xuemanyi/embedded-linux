#include <stdio.h>

enum Color{
    RED,
    GREEN,
    BLUE
};

int main(void)
{
    enum Color c = GREEN;

    printf("%d\n", c);

    return 0;
}