#include "stringwrapper.h"

/**
 * _strtok - a function breaks a string into a sequence of tokens.
 * @str: original string
 * @delim: delimiter for breaking string
 * Return: pointer to new string.
 */
char *_strtok(char *str, const char *delim)
{
	return (strtok(str, delim));
}
