#include <stdio.h>

int run_task(int ok)
{
    if (!ok) {
        return -1;
    }

    return 0;
}

int main(void)
{
    int ret = run_task(1);

    if (ret != 0) {
        fprintf(stderr, "run_task failed\n");
        return 1;
    }

    return 0;
}
