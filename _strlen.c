#include "stringwrapper.h"

/**
 * _strlen - a function that returns the length of a string.
 * @s: input string
 * Return: length of string
 */
size_t _strlen(const char *s)
{
	const char *p = s;

	while (*s)
		++s;
	return (s - p);
}
