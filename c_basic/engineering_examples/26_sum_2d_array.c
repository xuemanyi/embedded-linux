#include <stdio.h>

int main(void)
{
    int a[2][2] = {{1, 2}, {3, 4}};
    int sum = 0;
    int i;
    int j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            sum += a[i][j];
        }
    }

    printf("%d\n", sum);

    return 0;
}