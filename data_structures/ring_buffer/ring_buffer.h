#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct ring_buffer ring_buffer_t;

ring_buffer_t *ring_buffer_create(size_t capacity);
void ring_buffer_destroy(ring_buffer_t *rb);

void ring_buffer_reset(ring_buffer_t *rb);

size_t ring_buffer_write(ring_buffer_t *rb, const uint8_t *data, size_t len);
size_t ring_buffer_read(ring_buffer_t *rb, uint8_t *data, size_t len);

size_t ring_buffer_size(const ring_buffer_t *rb);
size_t ring_buffer_capacity(const ring_buffer_t *rb);
size_t ring_buffer_free_space(const ring_buffer_t *rb);

bool ring_buffer_is_empty(const ring_buffer_t *rb);
bool ring_buffer_is_full(const ring_buffer_t *rb);

#endif