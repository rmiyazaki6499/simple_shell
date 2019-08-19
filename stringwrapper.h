#ifndef STRINGWRAPPER_H
#define STRINGWRAPPER_H

#include <string.h>
#include <sys/types.h>

size_t _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strtok(char *str, const char *delim);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *s);
ssize_t get_nargs(char *s, char *delim);
char **strtow(char *s, char *delim);

#endif /* STRINGWRAPPER_H */
