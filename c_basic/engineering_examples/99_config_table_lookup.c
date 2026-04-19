#include <stdio.h>

struct config_item {
    int id;
    int period_ms;
};

int main(void)
{
    int i;
    struct config_item tables[] = {
        {100, 10},
        {200, 100},
    };

    for (i = 0; i < 2; i++) {
        if (tables[i].id == 200) {
            printf("%d\n", tables[i].period_ms);
        }
    }

    return 0;
}