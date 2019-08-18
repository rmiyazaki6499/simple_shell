#include "stringwrapper.h"

/**
 * _strtok - a function breaks a string into a sequence of tokens.
 * @str: original string
 * @delim: delimiter for breaking string
 * Return: pointer to new string.
 */
char *_strtok(char *str, const char *delim)
{
	static char *s;
	size_t d_len;

	if (!delim)
		return (NULL);

	if (str)
		s = str;

	if (!s || !*s)
		return (NULL);
	str = s;

	d_len = _strlen(delim);
	while (*s)
	{
		if (_strncmp(s, delim, d_len) == 0)
		{
			*s = '\0';
			s += d_len;
			break;
		}
		s++;
	}

	return (str);
}
