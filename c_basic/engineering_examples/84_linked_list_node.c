#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

int main(void)
{
    struct node *n1 = malloc(sizeof(*n1));
    struct node *n2 = malloc(sizeof(*n2));

    if (n1 == NULL || n2 == NULL) {
        free(n1);
        free(n2);
        return 1;
    }

    n1->value = 1;
    n1->next = n2;
    n2->value = 2;
    n2->next = NULL;

    printf("%d\n", n1->next->value);
    free(n2);
    free(n1);

    return 0;
}