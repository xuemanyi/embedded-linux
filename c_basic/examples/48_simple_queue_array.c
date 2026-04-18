#include <stdio.h>

int main(void)
{
    int queue[5];
    int front = 0, rear = 0;

    queue[rear++] = 10;
    queue[rear++] = 20;

    printf("pop=%d\n", queue[front++]);
    printf("pop=%d\n", queue[front++]);

    return 0;
}