#include <stdio.h>

struct status_bits {
    unsigned int ready : 1;
    unsigned int error : 1;
};

int main(void)
{
    struct status_bits s = {1, 0};

    printf("%u %u\n", s.ready, s.error);

    return 0;
}