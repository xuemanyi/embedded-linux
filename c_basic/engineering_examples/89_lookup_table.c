#include <stdio.h>

static const char *g_names[] = {"idle", "run", "stop"};

int main(void)
{
    int id = 1;

    printf("%s\n", g_names[id]);

    return 0;
}