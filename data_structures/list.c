#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_node(int value)
{
    struct node *new_node = malloc(sizeof(struct node));
    
    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = value;
    new_node->next = NULL;

    return new_node;
}

void insert_head(struct node **head, int value)
{
    struct node *new_node = create_node(value);

    if (new_node == NULL) {
        return;
    }

    new_node->next = *head;
    *head = new_node;
}

void insert_tail(struct node **head, int value)
{
    struct node *new_node = create_node(value);
    struct node *current;

    if (new_node == NULL) {
        return;
    }

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

void print_list(struct node *head)
{
    struct node *current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

struct node *find_node(struct node *head, int value)
{
    struct node *current = head;

    while (current != NULL) {
        if (current->data == value) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

int delete_value(struct node **head, int value)
{
    struct node *current = *head;
    struct node *prev = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            return 1;
        }

        prev = current;
        current = current->next;
    }

    return 0;
}

void destroy_list(struct node **head)
{
    struct node *current = *head;
    struct node *next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    *head = NULL;
}

int main(void)
{
    struct node *head = NULL;
    struct node *found;

    insert_head(&head, 10);
    insert_head(&head, 20);
    insert_tail(&head, 30);
    insert_tail(&head, 40);

    print_list(head);

    found = find_node(head, 30);
    if (found != NULL) {
        printf("Found: %d\n", found->data);
    } else {
        printf("Not Found\n");
    }

    delete_value(&head, 20);
    print_list(head);

    destroy_list(&head);
    print_list(head);

    return 0;
}