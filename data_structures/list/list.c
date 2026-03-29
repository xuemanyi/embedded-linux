#include "list.h"

#include <stdio.h>
#include <stdlib.h>


/* Internel node */
struct node {
    int data;
    struct node *next;
};

/* List definition */
struct list {
    struct node *head;
    size_t size;
};

/* Create list */
list_t *list_create(void)
{
    list_t *list = malloc(sizeof(*list));
    if (list == NULL) {
        return NULL;
    }

    list->head = NULL;
    list->size = 0;

    return list;
}

/* Destroy list */
void list_destroy(list_t *list)
{
    struct node *current;
    struct node *next;

    if (list == NULL) {
        return;
    }

    current = list->head;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

/* Create node */
static struct node *create_node(int value)
{
    struct node *n = malloc(sizeof(*n));
    if (n == NULL) {
        return NULL;
    }

    n->data = value;
    n->next = NULL;

    return n;
}

/* Insert head */
int list_insert_head(list_t *list, int value)
{
    struct node *n;

    if (list == NULL) {
        return -1;
    }

    n = create_node(value);
    if (n == NULL) {
        return -1;
    }

    n->next = list->head;
    list->head = n;
    list->size++;

    return 0;
}

/* Insert tail */
int list_insert_tail(list_t *list, int value)
{
    struct node *n;
    struct node *current;

    if (list == NULL) {
        return -1;
    }

    n = create_node(value);
    if (n == NULL) {
        return -1;
    }

    if (list->head == NULL) {
        list->head = n;
        list->size++;
        
        return 0;
    }

    current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = n;
    list->size++;

    return 0;
}

/* Delete value*/
int list_delete(list_t *list, int value)
{
    struct node *current;
    struct node *prev = NULL;

    if (list == NULL || list->head == NULL) {
        return  0;
    }

    current = list->head;

    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            list->size--;
            
            return 1;
        }

        prev = current;
        current = current->next;
    }

    return 0;
}

/* Find */
int list_find(list_t *list, int value)
{
    struct node *current;

    if (list == NULL) {
        return 0;
    }

    current = list->head;

    while (current != NULL) {
        if (current->data == value) {
            return 1;
        }

        current = current->next;
    }

    return 0;
}

/* Print */
void list_print(const list_t *list)
{
    const struct node *current;

    if (list == NULL) {
        printf("NULL\n");
        return;
    }

    current = list->head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

/* Size */
size_t list_size(const list_t *list)
{
    if (list == NULL) {
        return 0;
    }

    return list->size;
}