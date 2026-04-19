#include <stdio.h>

static void print_usage(const char *prog)
{
    printf("usage: %s\n", prog);
}

int main(int argc, char *argv[])
{
    (void)argc;

    print_usage(argv[0]);

    return 0;
}