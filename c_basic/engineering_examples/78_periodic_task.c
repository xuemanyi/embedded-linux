#include <stdio.h>

int main(void)
{
    int tick;

    for (tick = 1; tick <= 10; tick++) {
        if ((tick % 5) == 0) {
            printf("run at %d\n", tick);
        }
    }

    return 0;
}