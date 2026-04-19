#include <stdio.h>

int main(void)
{
    int tick;
    int timeout = 5;

    for (tick = 0; tick < 10; tick++) {
        if (tick >= timeout) {
            printf("timeout\n");
            break;
        }
    }

    return 0;
}
