#include <stdio.h>

int main(void)
{
    int day = 2;

    switch (day) {
        case 1: printf("Monday\n");     break;
        case 2: printf("Tuesday\n");    break;
        default: printf("Other day\n"); break;
    }

    return 0;
}