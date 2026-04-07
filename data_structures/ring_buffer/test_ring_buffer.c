#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "ring_buffer.h"

static void print_buffer(const uint8_t *buf, size_t len)
{
    size_t i;

    for (i = 0; i < len; i++) {
        printf("%c", buf[i]);
    }
    printf("\n");
}

int main(void)
{
    ring_buffer_t *rb;
    uint8_t write_data1[] = "hello";
    uint8_t write_data2[] = "world123";
    uint8_t read_buf[64];
    size_t n;

    rb = ring_buffer_create(10);
    if (rb == NULL) {
        printf("ring_buffer_create failed\n");
        return 1;
    }

    printf("capacity = %zu\n", ring_buffer_capacity(rb));
    printf("size = %zu\n", ring_buffer_size(rb));
    printf("empty = %d\n", ring_buffer_is_empty(rb));

    n = ring_buffer_write(rb, write_data1, strlen((char *)write_data1));
    printf("write %zu bytes: %s\n", n, write_data1);
    printf("size = %zu\n", ring_buffer_size(rb));

    memset(read_buf, 0, sizeof(read_buf));
    n = ring_buffer_read(rb, read_buf, 3);
    printf("read %zu bytes: ", n);
    print_buffer(read_buf, n);
    printf("size = %zu\n", ring_buffer_size(rb));

    n = ring_buffer_write(rb, write_data2, strlen((char *)write_data2));
    printf("write %zu bytes: %s\n", n, write_data2);
    printf("size = %zu\n", ring_buffer_size(rb));
    printf("full = %d\n", ring_buffer_is_full(rb));

    memset(read_buf, 0, sizeof(read_buf));
    n = ring_buffer_read(rb, read_buf, sizeof(read_buf));
    printf("read %zu bytes: ", n);
    print_buffer(read_buf, n);
    printf("size = %zu\n", ring_buffer_size(rb));
    printf("empty = %d\n", ring_buffer_is_empty(rb));

    ring_buffer_destroy(rb);
    return 0;
}