#include <stdio.h>

int main(void)
{
    int tries;

    for (tries = 0; tries < 3; tries++) {
        if (tries == 2) {
            printf("success\n");
            break;
        }
    }

    return 0;
}