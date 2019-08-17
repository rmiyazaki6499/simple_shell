#include <stdlib.h>
#include "stringwrapper.h"

/**
 * strtow - a function that splits a string into words.
 * @s: input string
 * @delim: delimiter
 * Return: a pointer to an array of strings (words)
 */
char **strtow(char *s, char *delim)
{
	ssize_t nargs;
	char *token, **buffer;

	nargs = get_nargs(s, delim);
	if (nargs < 1)
		return (NULL);

	buffer = malloc(sizeof(*buffer) * (nargs + 1));
	if (!buffer)
		return (NULL);

	nargs = 0;
	token = _strtok(s, delim);
	while (token)
	{
		if (!*token)
		{
			token = _strtok(NULL, delim);
			continue;
		}

		buffer[nargs++] = token;
		token = _strtok(NULL, delim);
	}
	buffer[nargs] = NULL;

	return (buffer);
}
