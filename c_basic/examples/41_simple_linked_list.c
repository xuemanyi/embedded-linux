#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main(void)
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));

    if (head == NULL || second == NULL) {
        free(head);
        free(second);
        return 1;
    }

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = NULL;

    printf("%d -> %d\n", head->data, head->next->data);

    free(second);
    free(head);

    return 0;
}