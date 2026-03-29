#include "list.h"

#include <stdio.h>

int main(void)
{
    list_t *list;

    list = list_create();
    if (list == NULL) {
        printf("Failed to create list\n");
        return 1;
    }

    list_insert_head(list, 10);
    list_insert_head(list, 20);
    list_insert_tail(list, 30);
    list_insert_tail(list, 40);

    printf("List: ");
    list_print(list);

    /* Find */
    if (list_find(list, 30)) {
        printf("Found 30\n");
    } else {
        printf("Not found 30\n");
    }

    /* Delete */
    if (list_delete(list, 20)) {
        printf("Deleted 20\n");
    } else {
        printf("Deleted failed\n");
    }

    printf("List after delete: ");
    list_print(list);

    /* Size */
    printf("Size: %zu", list_size(list));

    /* Destroy */
    list_destroy(list);

    return 0;
}