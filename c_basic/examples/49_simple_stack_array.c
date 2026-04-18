#include <stdio.h>

int main(void)
{
    int stack[5];
    int top = -1;

    stack[++top] = 10;
    stack[++top] = 20;

    printf("pop=%d\n", stack[top--]);
    printf("pop=%d\n", stack[top--]);

    return 0;
}