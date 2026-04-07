#include "ring_buffer.h"

#include <stdlib.h>
#include <string.h>

struct ring_buffer {
    uint8_t *buffer;
    size_t capacity;
    size_t head;
    size_t tail;
    size_t size;
};

ring_buffer_t *ring_buffer_create(size_t capacity)
{
    ring_buffer_t *rb;

    if (capacity == 0) {
        return NULL;
    }

    rb = (ring_buffer_t *)malloc(sizeof(ring_buffer_t));
    if (rb == NULL) {
        return NULL;
    }

    rb->buffer = (uint8_t *)malloc(capacity);
    if (rb->buffer == NULL) {
        free(rb);
        return NULL;
    }

    rb->capacity = capacity;
    rb->head = 0;
    rb->tail = 0;
    rb->size = 0;

    return rb;
}

void ring_buffer_destroy(ring_buffer_t *rb)
{
    if (rb == NULL) {
        return;
    }

    free(rb->buffer);
    rb->buffer = NULL;
    free(rb);
}

void ring_buffer_reset(ring_buffer_t *rb)
{
    if (rb == NULL) {
        return;
    }

    rb->head = 0;
    rb->tail = 0;
    rb->size = 0;
}

size_t ring_buffer_write(ring_buffer_t *rb, const uint8_t *data, size_t len)
{
    size_t writable;
    size_t first_part;
    size_t second_part;

    if (rb == NULL || data == NULL || len == 0) {
        return 0;
    }

    writable = rb->capacity - rb->size;
    if (len > writable) {
        len = writable;
    }

    if (len == 0) {
        return 0;
    }

    first_part = rb->capacity - rb->tail;
    if (first_part > len) {
        first_part = len;
    }

    memcpy(rb->buffer + rb->tail, data, first_part);

    second_part = len - first_part;
    if (second_part > 0) {
        memcpy(rb->buffer, data + first_part, second_part);
    }

    rb->tail = (rb->tail + len) % rb->capacity;
    rb->size += len;

    return len;
}

size_t ring_buffer_read(ring_buffer_t *rb, uint8_t *data, size_t len)
{
    size_t readable;
    size_t first_part;
    size_t second_part;

    if (rb == NULL || data == NULL || len == 0) {
        return 0;
    }

    readable = rb->size;
    if (len > readable) {
        len = readable;
    }

    if (len == 0) {
        return 0;
    }

    first_part = rb->capacity - rb->head;
    if (first_part > len) {
        first_part = len;
    }

    memcpy(data, rb->buffer + rb->head, first_part);

    second_part = len - first_part;
    if (second_part > 0) {
        memcpy(data + first_part, rb->buffer, second_part);
    }

    rb->head = (rb->head + len) % rb->capacity;
    rb->size -= len;

    return len;
}

size_t ring_buffer_size(const ring_buffer_t *rb)
{
    if (rb == NULL) {
        return 0;
    }

    return rb->size;
}

size_t ring_buffer_capacity(const ring_buffer_t *rb)
{
    if (rb == NULL) {
        return 0;
    }

    return rb->capacity;
}

size_t ring_buffer_free_space(const ring_buffer_t *rb)
{
    if (rb == NULL) {
        return 0;
    }

    return rb->capacity - rb->size;
}

bool ring_buffer_is_empty(const ring_buffer_t *rb)
{
    if (rb == NULL) {
        return true;
    }

    return rb->size == 0;
}

bool ring_buffer_is_full(const ring_buffer_t *rb)
{
    if (rb == NULL) {
        return false;
    }

    return rb->size == rb->capacity;
}