#include <stdio.h>

struct user {
    int id;
    int age;
};

int main(void)
{
    struct user u = {0};

    printf("%d %d\n", u.id, u.age);

    return 0;
}