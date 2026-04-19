#include <stdio.h>

struct addr {
    int port;
};

struct server {
    struct addr a;
};

int main(void)
{
    struct server s = {{9000}};

    printf("%d\n", s.a.port);

    return 0;
}