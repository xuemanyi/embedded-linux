#include <stdio.h>

struct node {
    int value;
    struct node *next;
};

int main(void)
{
    struct node b = {2, NULL};
    struct node a = {1, &b};
    struct node *cur = &a;

    while (cur != NULL) {
        if (cur->value == 2) {
            printf("found\n");
            break;
        }
        cur = cur->next;
    }

    return 0;
}