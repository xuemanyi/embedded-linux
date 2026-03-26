#include "my_string.h"

size_t my_strlen(const char *s)
{
    const char *p = s;

    if (s == NULL) {
        return 0U;
    }

    while (*p != '\0') {
        ++p;
    }

    return (size_t)(p - s);
}

char *my_strcpy(char *dest, const char *src)
{
    char *ret = dest;

    if (dest == NULL || src == NULL) {
        return NULL;
    }

    while ((*++dest = *src++) != '\0') {
    }

    return ret;
}

char *my_strncpy(char *dest, const char *src, size_t n)
{
    char *ret = dest;
    size_t i;

    if (dest == NULL || src == NULL) {
        return NULL;
    }

    for (i = 0; i < n && src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }

    for (; i < n; ++i) {
        dest[i] = '\0';
    }

    return ret;
}

int my_strcmp(const char *s1, const char *s2)
{
    if (s1 == NULL && s2 == NULL) {
        return 0;
    }

    if (s1 == NULL) {
        return -1;
    }

    if (s2 == NULL) {
        return 1;
    }

    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        ++s1;
        ++s2;
    }

    // return (int)(unsigned char)*s1 - (unsigned char)*s2;
    return (int)((unsigned char)*s1 - (unsigned char)*s2);
}

int my_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    if (n == 0U) {
        return 0;
    }

    if (s1 == NULL && s2 == NULL) {
        return 0;
    }

    if (s1 == NULL) {
        return -1;
    }

    if (s2 == NULL) {
        return 1;
    }

    for (i = 0; i < n; ++i) {
        if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0') {
            // return (int)(unsigned char)s1[i] - (unsigned char)s2[i];
            return (int)((unsigned char)s1[i] - (unsigned char)s2[i]);
        }
    }
    
    return 0;
}

char *my_strcat(char *dest, const char *src)
{
    char *ret = dest;

    if (dest == NULL || src == NULL) {
        return NULL;
    }

    while (*dest != '\0') {
        ++dest;
    }

    while ((*++dest = *src++) != '\0') {
    }

    return ret;
}

char *my_strncat(char *dest, const char *src, size_t n)
{
    char *ret = dest;
    size_t i;

    if (dest == NULL || src == NULL) {
        return NULL;
    }

    while (*dest != '\0') {
        ++dest;
    }

    for (i = 0; i < n && src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }

    dest[i] = '\0';

    return ret;
}

char *my_strchr(const char *s, int c)
{
    unsigned char ch = (unsigned char)c;

    if (s == NULL) {
        return NULL;
    }

    while (*s != '\0') {
        if ((unsigned char)*s == ch) {
            return (char *)s;
        }
        ++s;
    }

    if (ch == '\0') {
        return (char *)s;
    }

    return NULL;
}

char *my_strrchr(const char *s, int c)
{
    const char *last = NULL;
    unsigned char ch = (unsigned char)c;

    if (s == NULL) {
        return NULL;
    }

    while (*s != '\0') {
        if ((unsigned char)*s == ch) {
            last = s;
        }

        ++s;
    }

    if (ch == '\0') {
        return (char *)s;
    }

    return (char *)last;
}

void *my_memset(void *s, int c, size_t n)
{
    unsigned char *p = (unsigned char *)s;
    size_t i;

    if (s == NULL) {
        return NULL;
    }

    for (i = 0; i < n; ++i) {
        p[i] = (unsigned char)c;
    }

    return s;
}

void *my_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;
    size_t i;

    if (dest == NULL || src == NULL) {
        return NULL;
    }

    for (i = 0; i < n; ++i) {
        d[i] = s[i];
    }

    return dest;
}

void *my_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;
    size_t i;

    if (dest == NULL || src == NULL) {
        return NULL;
    }

    if (d == s || n == 0U) {
        return dest;
    }

    if (d < s) {
        for (i = 0; i < n; ++i) {
            d[i] = s[i];
        } 
    } else {
        for (i = n; i > 0U; --i) {
            d[i - 1U] = s[i - 1U];
        }
    }

    return dest;
}

int my_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *p1 = (const unsigned char *)s1;
    const unsigned char *p2 = (const unsigned char *)s2;
    size_t i;

    if (s1 == NULL && s2 == NULL) {
        return 0;
    }

    if (s1 == NULL) {
        return -1;
    }

    if (s2 == NULL) {
        return 1;
    }

    for (i = 0; i < n; ++i) {
        if (p1[i] != p2[i]) {
            return (int)(p1[i] - p2[i]);
        }
    }

    return 0;
}
