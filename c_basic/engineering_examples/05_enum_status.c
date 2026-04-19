#include <stdio.h>

typedef enum {
    STATUS_OK = 0,
    STATUS_ERROR = -1,
} status_t;

int main(void)
{
    status_t status = STATUS_OK;

    printf("status=%d\n", status);

    return 0;
}