#include <stdio.h>

typedef enum {
    MODE_IDLE = 0,
    MODE_RUN,
} mode_t;

static const char *mode_to_string(mode_t mode)
{
    switch (mode) {
        case MODE_IDLE: return "idle";
        case MODE_RUN:  return "run";
        default:        return "unkonwn";
    }
}

int main(void)
{
    printf("%s\n", mode_to_string(MODE_RUN));

    return 0;
}