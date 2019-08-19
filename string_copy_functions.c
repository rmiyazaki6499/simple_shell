#include "stringwrapper.h"
#include "stdlibwrapper.h"

/**
 * _strcpy - a function that copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: destination
 * @src: source
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	unsigned int i;

	for (i = 0; src[i] != '\0'; ++i)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}

/**
 * _strncpy - a function that copies a string.
 * @dest: initial string
 * @src: string to append to dest
 * @n: the max bytes to use
 * Return: pointer to copied string
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t length;

	for (length = 0; src[length] != '\0' && length < n; length++)
		dest[length] = src[length];
	for ( ; length < n; length++)
		dest[length] = '\0';
	return (dest);
}

/**
 * _strdup - a function that returns a pointer
 * to a newly allocated space in memory,
 * which contains a copy of string
 * @s: input string
 * Return: pointer to the newly allocated space in memory
 */
char *_strdup(const char *s)
{
	char *p, *str;
	unsigned int i, length;

	if (s == NULL)
		return (0);

	for (length = 0; s[length] != '\0'; length++)
		;

	p = (char *) malloc(sizeof(char) * length + 1);
	str = p;

	if (p == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		p[i] = s[i];

	p[i] = '\0';

	return (str);
}

/**
 * _strndup - a function that returns a pointer
 * to a newly allocated space in memory,
 * which contains a copy of string
 * @s: input string
 * @n: bytes to duplicate
 * Return: pointer to the newly allocated space in memory
 */
char *_strndup(const char *s, size_t n)
{
	char *p, *str;
	unsigned int i, length;

	if (s == NULL)
		return (0);

	for (length = 0; s[length] != '\0'; length++)
		;

	p = (char *) malloc(sizeof(char) * n + 1);
	str = p;

	if (p == NULL)
		return (NULL);

	for (i = 0; i < length && i < n; i++)
		p[i] = s[i];

	p[i] = '\0';

	return (str);
}

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
