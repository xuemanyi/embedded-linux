#include <stdio.h>

typedef enum {
    ST_IDLE = 0,
    ST_RUN,
    ST_STOP,
} state_t;

int main(void)
{
    state_t st = ST_RUN;

    switch (st) {
        case ST_IDLE:
            printf("idle\n");
            break;
        case ST_RUN:
            printf("run\n");
            break;
        case ST_STOP:
            printf("stop\n");
            break;
    }

    return 0;
}