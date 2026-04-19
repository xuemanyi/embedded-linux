#include <stdio.h>

static int g_open_count;

static void resource_open(void)
{
    g_open_count++;
}

static void resource_close(void)
{
    g_open_count--;
}

int main(void)
{
    resource_open();
    resource_close();
    printf("%d\n", g_open_count);
    
    return 0;
}