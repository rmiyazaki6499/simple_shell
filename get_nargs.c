#include <string.h>
#include <sys/types.h>

ssize_t get_nargs(char *s, char *delim)
{
	size_t d_len;

	if (!s || !delim)
		return (-1);

	if (!*s)
		return (0);

	d_len = _strlen(delim);
	while (*s && _strncmp(s, delim, d_len) == 0)
		s += d_len;

	if (*s)
	{
		while (*s && _strncmp(s, delim, d_len) != 0)
			s++;

		return (1 + get_nargs(s, delim));
	}

	return (0);
}
