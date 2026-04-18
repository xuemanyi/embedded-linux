#include <stdio.h>

struct Student {
    char name[20];
    int age;
};

int main(void)
{
    struct Student s = {"Tom", 18};

    printf("%s %d\n", s.name, s.age);

    return 0;
}