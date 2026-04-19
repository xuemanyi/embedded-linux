#include <stdio.h>

int main(void)
{
    int samples[] = {0, 1, 1, 1};
    int stable = 0;
    int i;

    for (i = 0; i < 4; i++) {
        if (samples[i] == 1) {
            stable++;
        }
    }

    if (stable >= 3) {
        printf("pressed\n");
    }

    return 0;
}