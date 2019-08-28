#include "stdlibwrapper.h"
#include <unistd.h>

#define BUFSIZE 120

/**
 * _getdelim - get a line from a file
 * @lineptr: buffer to fill with contents of line
 * @n: size of buffer to fill
 * @fd: file to read from
 * @delim: line delimiter in the file
 *
 * Return: Number of bytes read from the file
 */
ssize_t _getdelim(char **lineptr, size_t *n, int fd, char delim)
{
	char buf[BUFSIZE];
	ssize_t bytes_read;
	size_t i = 0;

	if (!lineptr || !n)
		return (-1);
	if (!*lineptr && !*n)
	{
		*lineptr = malloc(sizeof(**lineptr) * BUFSIZE);
		if (!*lineptr)
			return (-1);
		*n = BUFSIZE;
	}
	while (1)
	{
		bytes_read = read(fd, buf, BUFSIZE);
		if (bytes_read < 1)
			return (-1);
		while (i < *n)
		{
			if (bytes_read < BUFSIZE && i == (size_t)bytes_read)
				break;
			(*lineptr)[i] = buf[i % BUFSIZE];
			if (buf[i % BUFSIZE] == delim)
			{
				i++;
				break;
			}
			i++;
		}
		if (i < *n || buf[i - 1] == delim)
			break;
		*lineptr = realloc(*lineptr, *n + BUFSIZE);
		if (!*lineptr)
			return (-1);
		*n += BUFSIZE;
	}
	return (i);
}

/**
 * _getline - get a line from a file
 * @lineptr: buffer to fill with contents of line
 * @n: size of buffer to fill
 * @fd: file to read from
 *
 * Return: Number of bytes read from the file
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	return (_getdelim(lineptr, n, fd, '\n'));
}
