#include <stdio.h>

#define EXPECT_EQ(actual, expected) \
    do { \
        if ((actual) != (expected)) { \
            printf("fail\n"); \
            return 1; \
        } \
    } while (0)

int main(void)
{
    EXPECT_EQ(2 + 2, 4);
    printf("pass\n");

    return 0;
}