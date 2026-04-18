#include <stdio.h>

#define SIZE 3

int main(void)
{
    int buf[SIZE] = {0};
    int head = 0;
    int tail = 0;
    int count = 0;
    int value;

    /* Push 10 */
    value = 10;
    if (count < SIZE) {
        buf[tail] = value;
        tail = (tail + 1) % SIZE;
        count++;
        printf("push=%d, head=%d, tail=%d, count=%d\n", value, head, tail, count);
    } else {
        printf("buffer full, cannot push %d\n", value);
    }

    /* Push 20 */
    value = 20;
    if (count < SIZE) {
        buf[tail] = value;
        tail = (tail + 1) % SIZE;
        count++;
        printf("push=%d, head=%d, tail=%d, count=%d\n", value, head, tail, count);
    } else {
        printf("buffer full, cannot push %d\n", value);
    }

    /* Push 30 */
    value = 30;
    if (count < SIZE) {
        buf[tail] = value;
        tail = (tail + 1) % SIZE;
        count++;
        printf("push=%d, head=%d, tail=%d, count=%d\n", value, head, tail, count);
    } else {
        printf("buffer full, cannot push %d\n", value);
    }

    /* Push 40 */
    value = 40;
    if (count < SIZE) {
        buf[tail] = value;
        tail = (tail + 1) % SIZE;
        count++;
        printf("push=%d, head=%d, tail=%d, count=%d\n", value, head, tail, count);
    } else {
        printf("buffer full, cannot push %d\n", value);
    }

    /* Push 50 */
    value = 50;
    if (count < SIZE) {
        buf[tail] = value;
        tail = (tail + 1) % SIZE;
        count++;
        printf("push=%d, head=%d, tail=%d, count=%d\n", value, head, tail, count);
    } else {
        printf("buffer full, cannot push %d\n", value);
    }

    /* Pop one element */
    if (count > 0) {
        printf("pop=%d\n", buf[head]);
        head = (head + 1) % SIZE;
        count--;
        printf("after pop, head=%d, tail=%d, count=%d\n", head, tail, count);
    } else {
        printf("buffer empty\n");
    }

    return 0;
}