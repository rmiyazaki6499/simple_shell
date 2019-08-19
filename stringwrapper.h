#ifndef STRINGWRAPPER_H
#define STRINGWRAPPER_H

#include <strings.h>

size_t _strlen(const char *s);
{
	return (strlen(s));
}
int _strncmp(const char *s1, const char *s2, size_t n);
{
	return (strcmp(s1, s2, n));
}
char *_strtok(char *str, const char *delim);
{
	return (strtok(str, delim));
}
char *_strcpy(char *dest, const char *src);
{
	return (strcpy(dest, src));
}
char *_strcat(char *dest, const char *src);
{
	return (strcat(dest, src));
}


#endif /* STRINGWRAPPER_H */
