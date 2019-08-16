#ifndef INPUTHELPER_H
#define INPUTHELPER_H

#include <stdio.h>

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	return (getline(lineptr, n, stream));
}

#endif /* INPUTHELPER_H */
