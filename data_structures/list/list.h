#ifndef LIST_H
#define LIST_H

#include <stddef.h>

/* Opaque type */
typedef struct list list_t;

/* Create / destroy */
list_t *list_create(void);
void list_destroy(list_t *list);

/* Insert */
int list_insert_head(list_t *list, int value);
int list_insert_tail(list_t *list, int value);

/* Delete */
int list_delete(list_t *list, int value);

/* Find */
int list_find(list_t *list, int value);

/* Print */
void list_print(const list_t *list);

/* Utility */
size_t list_size(const list_t *list);

#endif