#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

int main(void)
{
    struct node a = {1, NULL};
    struct node b = {2, NULL};
    int count = 0;
    struct node *cur;

    a.next = &b;

    for (cur = &a; cur != NULL; cur = cur->next) {
        count++;
    }

    printf("%d\n", count);

    return 0;
}