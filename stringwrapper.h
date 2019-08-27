#ifndef STRINGWRAPPER_H
#define STRINGWRAPPER_H

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int _putchar(char c);
void _puts(char *str);
void print_error(char *argument);
void _print_number(int n);
size_t _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strtok(char *str, const char *delim);
char *_strcpy(char *dest, const char *src);
char *_strncpy(char *dest, const char *src, size_t n);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *s);
char *_strndup(const char *s, size_t n);
ssize_t get_nargs(char *s, char *delim);
char **strtow(char *s, char *delim);

#endif /* STRINGWRAPPER_H */
