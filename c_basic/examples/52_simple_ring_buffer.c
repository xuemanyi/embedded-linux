#include <stdio.h>

#define SIZE 3

static int ring_push(int buf[], int *tail, int *count, int value)
{
    if (*count >= SIZE) {
        return -1;
    }

    buf[*tail] = value;
    *tail = (*tail + 1) % SIZE;
    (*count)++;
    return 0;
}

static int ring_pop(int buf[], int *head, int *count, int *value)
{
    if (*count <= 0) {
        return -1;
    }

    *value = buf[*head];
    *head = (*head + 1) % SIZE;
    (*count)--;
    return 0;
}

int main(void)
{
    int buf[SIZE] = {0};
    int head = 0;
    int tail = 0;
    int count = 0;
    int value = 0;

    if (ring_push(buf, &tail, &count, 10) == 0)
        printf("push 10 ok\n");
    else
        printf("push 10 failed\n");

    if (ring_push(buf, &tail, &count, 20) == 0)
        printf("push 20 ok\n");
    else
        printf("push 20 failed\n");

    if (ring_push(buf, &tail, &count, 30) == 0)
        printf("push 30 ok\n");
    else
        printf("push 30 failed\n");

    if (ring_push(buf, &tail, &count, 40) == 0)
        printf("push 40 ok\n");
    else
        printf("push 40 failed\n");

    if (ring_pop(buf, &head, &count, &value) == 0)
        printf("pop=%d\n", value);
    else
        printf("pop failed\n");

    return 0;
}