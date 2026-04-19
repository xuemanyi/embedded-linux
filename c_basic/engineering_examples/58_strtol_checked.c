#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *end = NULL;
    long value = strtoll("6", &end, 10);

    if (end == NULL || *end != '\0') {
        return 1;
    }
    printf("%ld\n", value);

    return 0;
}