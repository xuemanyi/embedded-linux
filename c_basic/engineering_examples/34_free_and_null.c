#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = malloc(sizeof(*p));

    if (p == NULL) {
        return 1;
    }

    free(p);
    p = NULL;

    printf("%p\n", (void *)p); // (nil)
    
    return 0;
}