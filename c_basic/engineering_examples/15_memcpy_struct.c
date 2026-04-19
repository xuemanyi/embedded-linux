#include <stdio.h>
#include <string.h>

struct data {
    int a;
    int b;
};

int main(void)
{
    struct data src = {1, 2};
    struct data dst = {0};

    memcpy(&dst, &src, sizeof(dst));
    printf("%d %d\n", dst.a, dst.b);

    return 0;
}