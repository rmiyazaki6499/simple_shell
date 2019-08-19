#include <stdlib.h>
#include "stringwrapper.h"

char *strtow(char *s, char *delim)
{
	ssize_t nargs;
	char *token, *buffer;

	nargs = get_nargs(s, delim);
	if (nargs < 1)
		return (NULL);

	buffer = malloc(sizeof(*buffer) * nargs);
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

	return (buffer);
}
