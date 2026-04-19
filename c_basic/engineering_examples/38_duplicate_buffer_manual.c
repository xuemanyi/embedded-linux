#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char *src = "abc";
    size_t len = strlen(src);
    char *dst = malloc(len + 1);

    if (dst == NULL) {
        return 1;
    }

    memcpy(dst, src, len + 1);
    printf("%s\n", dst);

    free(dst);
    
    return 0;
}