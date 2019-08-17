#include "stringwrapper.h"

/**
 * _memcpy - a function that copies memory area.
 * @dest: copied memory area
 * @src: original memory area
 * @n: bytes from memory
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *p = dest;
	const char *s = src;

	while (n--)
		*p++ = *s++;
	return (dest);
}
