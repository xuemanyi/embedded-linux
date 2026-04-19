#include <stdio.h>

#define LOG_INFO(fmt, ...) \
    printf("[INFO] " fmt "\n", ##__VA_ARGS__);

int main(void)
{
    LOG_INFO("value=%d", 10);
    return 0;
}
