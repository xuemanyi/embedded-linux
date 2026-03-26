#include <stdio.h>
#include "my_string.h"

static void test_strlen(void)
{
    const char *s = "hello";

    printf("my_strlen(\"%s\") = %zu\n", s, my_strlen(s));
}

static void test_strcpy(void)
{
    char buf[32];

    my_strcpy(buf, "world");
    printf("my_strcpy -> %s\n", buf);
}

static void test_strncpy(void)
{
    char buf[16];

    my_memset(buf, 0, sizeof(buf));
    my_strncpy(buf, "abcdef", 3);
    printf("my_strncpy -> %s\n", buf);
}

static void test_strcat(void)
{
    char buf[32] = "hello";

    my_strcat(buf, "_world");
    printf("my_strcat -> %s\n", buf);
}

static void test_strchr(void)
{
    char *p = my_strchr("abcdef", 'd');

    if (p != NULL) {
        printf("my_strchr -> %s\n", p);
    } else {
        printf("my_strchr -> not found\n");
    }
}

static void test_memcpy(void)
{
    char src[8] = "1234567";
    char dst[8];

    my_memcpy(dst, src, sizeof(src));
    printf("my_memcpy -> %s\n", dst);
}

static void test_memmove(void)
{
    char buf[16] = "abcdef";

    my_memmove(buf + 2, buf, 4);
    printf("my_memmove -> %s\n", buf);
}

int main(void)
{
    test_strlen();
    test_strcpy();
    test_strncpy();
    test_strcat();
    test_strchr();
    test_memcpy();
    test_memmove();

    return 0;
}