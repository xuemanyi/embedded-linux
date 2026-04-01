#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

static void test_basic_operations(void)
{
	struct queue q;
	int value;
	int ret;

	queue_init(&q);

	printf("== After init ==\n");
	queue_print(&q);
	printf("is_empty: %s\n", queue_is_empty(&q) ? "true" : "false");
	printf("size: %zu\n\n", queue_size(&q));

	printf("== Enqueue 10, 20, 30 ==\n");
	ret = queue_enqueue(&q, 10);
	if (ret != 0) {
		printf("queue_enqueue failed\n");
		queue_destroy(&q);
		return;
	}

	ret = queue_enqueue(&q, 20);
	if (ret != 0) {
		printf("queue_enqueue failed\n");
		queue_destroy(&q);
		return;
	}

	ret = queue_enqueue(&q, 30);
	if (ret != 0) {
		printf("queue_enqueue failed\n");
		queue_destroy(&q);
		return;
	}

	queue_print(&q);
	printf("is_empty: %s\n", queue_is_empty(&q) ? "true" : "false");
	printf("size: %zu\n\n", queue_size(&q));

	printf("== PEEK ==\n");
	ret = queue_peek(&q, &value);
	if (ret == 0) {
		printf("front value: %d\n", value);
	} else {
		printf("queue_peek failed\n");
	}
	queue_print(&q);
	printf("\n");

	printf("== Dequeue step by step ==\n");
	while (!queue_is_empty(&q)) {
		ret = queue_dequeue(&q, &value);
		if (ret == 0) {
			printf("dequeue value: %d\n", value);
			queue_print(&q);
		} else {
			printf("queue_dequeue failed\n");
			break;
		}
	}
	printf("\n");

	printf("== Dequeue on empty queue ==\n");
	ret = queue_dequeue(&q, &value);
	if (ret != 0) {
		printf("queue_dequeue failed as expected\n");
	}
	printf("\n");

	printf("== Peek on empty queue ==\n");
	ret = queue_peek(&q, &value);
	if (ret != 0) {
		printf("queue_peek failed as expected\n");
	}
	printf("\n");

	queue_destroy(&q);
}

int main(void)
{
	test_basic_operations();
	
	return EXIT_SUCCESS;
}
