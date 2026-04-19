#include <stdio.h>

#define LOG_ERROR(fmt, ...) \
    fprintf(stderr, "[ERROR] " fmt "\n", ##__VA_ARGS__)

int main(void)
{
    LOG_ERROR("open failed");
    return 0;
}
