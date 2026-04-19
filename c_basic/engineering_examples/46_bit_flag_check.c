#include <stdio.h>

#define FLAG_READ  (1U << 0)
#define FLAG_WRITE (1U << 1)

int main(void)
{
    unsigned int flags = FLAG_READ | FLAG_WRITE;

    if ((flags & FLAG_WRITE) != 0U) {
        printf("write on\n");
    }

    return 0;
}