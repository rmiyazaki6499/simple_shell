#include "stringwrapper.h"

/**
 * _strncpy - a function that copies a string.
 * @dest: initial string
 * @src: string to append to dest
 * @n: the max bytes to use
 * Return: pointer to copied string
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	int length;

	for (length = 0; src[length] != '\0' && length < n; length++)
		dest[length] = src[length];
	for ( ; length < n; length++)
		dest[length] = '\0';
	return (dest);
}
