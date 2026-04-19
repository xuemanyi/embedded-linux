#include <stdio.h>

int main(void)
{
    int stack[4];
    int top = -1;

    stack[++top] = 10;
    stack[++top] = 20;

    printf("%d\n", stack[top--]);

    return 0;
}