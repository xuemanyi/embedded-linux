#include <stdio.h>

typedef struct {
    int id;
    char name[20];
} User;

int main(void)
{
    User u = {1, "Alice"};

    printf("%d %s\n", u.id, u.name);

    return 0;
}