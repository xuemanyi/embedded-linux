#include <stdio.h>

typedef struct {
    int value;
} counter_t;

static void counter_inc(counter_t *c)
{
    c->value++;
}

int main(void)
{
    counter_t c = {0};

    counter_inc(&c);
    printf("%d\n", c.value);

    return 0;
}