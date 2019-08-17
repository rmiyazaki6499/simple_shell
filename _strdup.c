#include "stringwrapper.h"
#include "stdlibwrapper.h"

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
