#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    bool ready = true;

    if (ready) {
        printf("ready\n");
    } else {
        printf("no ready\n");
    }

    return 0;
}