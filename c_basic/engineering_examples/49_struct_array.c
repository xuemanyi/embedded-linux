#include <stdio.h>

struct item {
    int id;
};

int main(void)
{
    struct item items[] = {{1}, {2}, {3}};

    printf("%d\n", items[2].id);

    return 0;
}