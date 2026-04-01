#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stddef.h>

struct node {
	int data;
	struct node *next;
};

struct queue {
	struct node *front;
	struct node *rear;
	size_t size;
};

void queue_init(struct queue *q);
bool queue_is_empty(const struct queue *q);
size_t queue_size(const struct queue *q);

int queue_enqueue(struct queue *q, int value);
int queue_dequeue(struct queue *q, int *value);
int queue_peek(const struct queue *q, int *value);

void queue_print(const struct queue *q);
void queue_destroy(struct queue *q);

#endif

