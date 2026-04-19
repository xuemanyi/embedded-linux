#include <stdio.h>

struct config {
    int enabled;
};

int main(void)
{
    struct config cfg = {1};
    struct config *p = &cfg;

    printf("%d\n", p->enabled);

    return 0;
}