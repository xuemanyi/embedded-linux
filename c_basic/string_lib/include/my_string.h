#ifndef MY_STRING_H
#define MY_STRING_H

#include <stddef.h>

size_t my_strlen(const char *s);

char *my_strcpy(char *dest, const char *src);
char *my_strncpy(char *dest, const char *src, size_t n);

int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, size_t n);

char *my_strcat(char *dest, const char *src);
char *my_strncat(char *dest, const char *src, size_t n);

char *my_strchr(const char *s, int c);
char *my_strrchr(const char *s, int c);

void *my_memset(void *s, int c, size_t n);
void *my_memcpy(void *dest, const void *src, size_t n);
void *my_memmove(void *dest, const void *src, size_t n);
int my_memcmp(const void *s1, const void *s2, size_t n);

#endif