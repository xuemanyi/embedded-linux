#include <stdio.h>

int main(void)
{
    int pool[3] = {100, 200, 300};
    int used[3] = {0};

    used[1] = 1;
    printf("%d %d\n", pool[1], used[1]);

    return 0;
}