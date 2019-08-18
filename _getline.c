#include "stringwrapper.h"
#include "stdlibwrapper.h"

/**
 * _getline - a function that reads an entire line from standard input.
 * @lineptr: pointer to an array of arguments
 * @n: number of bytes to allocate memory
 * @fd: file descriptor
 * Return: number of arguments read
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	static char *buffer;
	static size_t bufsize;
	char buf120[120];
	ssize_t bytes, position = 0;

	if (*lineptr)
	{
		if (*n > bufsize)
		{
			free(buffer);
			buffer = *lineptr;
		}
		else if ((*n < bufsize) || (*lineptr != buffer))
		{
			free(*lineptr);
			*n = bufsize;
		}
	}
	else if (!buffer)
	{
		buffer = malloc(120);
		bufsize = 120;
	}

	while ((bytes = read(fd, buf120, 120)))
	{
		if (bytes == -1)
			exit(1);

		bufsize += 120;
		buffer = _realloc(buffer, bufsize - 120, bufsize);
		_strncpy((buffer + position), buf120, bytes);
		position += bytes;
	}
	*lineptr = buffer;
	*n = bufsize;
	return (position);
}
