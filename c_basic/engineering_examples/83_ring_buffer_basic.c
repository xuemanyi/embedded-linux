#include <stdio.h>

#define SIZE 4

int main(void)
{
    int buf[SIZE];
    int head = 0;
    int tail = 0;
    int count = 0;

    buf[tail] = 11;
    tail = (tail + 1) % SIZE;
    count++;

    if (count > 0) {
        printf("%d\n",  buf[head]);
    }

    return 0;
}