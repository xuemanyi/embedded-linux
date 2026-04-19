#include <stdio.h>

struct person {
    int id;
    const char *name;
};

int main(void)
{
    struct person p = {1, "alice"};

    printf("%d %s\n", p.id, p.name);

    return 0;
}