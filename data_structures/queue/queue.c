#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

static struct node *queue_create_node(int value)
{
	struct node *new_node = malloc(sizeof(*new_node));

	if (new_node == NULL) {
		return NULL;
	}

	new_node->data = value;
	new_node->next = NULL;

	return new_node;
}

void queue_init(struct queue *q)
{
	if (q == NULL) {
		return;
	}

	q->front = NULL;
	q->rear = NULL;
	q->size = 0U;
}

bool queue_is_empty(const struct queue *q)
{
	if (q == NULL) {
		return true;
	}

	return q->front == NULL;
}

size_t queue_size(const struct queue *q)
{
	if (q == NULL) {
		return 0U;
	}

	return q->size;
}

int queue_enqueue(struct queue *q, int value)
{
	struct node *new_node;

	if (q == NULL) {
		return -1;
	}

	new_node = queue_create_node(value);
	if (new_node == NULL) {
		return -1;
	}

	if (q->rear == NULL) {
		q->front = new_node;
		q->rear = new_node;
	} else {
		q->rear->next = new_node;
		q->rear = new_node;
	}

	q->size++;

	return 0;
}

int queue_dequeue(struct queue *q, int *value)
{
	struct node *temp;

	if (q == NULL || value == NULL) {
		return -1;
	}

	if (queue_is_empty(q)) {
		return -1;
	}

	temp = q->front;
	*value = temp->data;
	q->front = temp->next;

	if (q->front == NULL) {
		q->rear = NULL;
	}

	free(temp);
	q->size--;
	
	return 0;
}

int queue_peek(const struct queue *q, int *value)
{
	if (q == NULL || value == NULL) {
		return -1;
	}

	if (queue_is_empty(q)) {
		return -1;
	}

	*value = q->front->data;

	return 0;
}

void queue_print(const struct queue *q)
{
	const struct node *current;
	
	if (q == NULL) {
		printf("queue is invalid\n");
		return;
	}

	printf("queue(size=%zu): front -> ", q->size);

	current = q->front;
	while (current != NULL) {
		printf("[%d]", current->data);
		if (current->next != NULL) {
			printf(" -> ");
		}
		current = current->next;
	}

	printf(" -> NULL\n");
}

void queue_destroy(struct queue *q)
{
	struct node *current;
	struct node *next_node;

	if (q == NULL) {
		return;
	}

	current = q->front;
	while (current != NULL) {
		next_node = current->next;
		free(current);
		current = next_node;
	}

	q->front = NULL;
	q->rear = NULL;
	q->size = 0U;
}
