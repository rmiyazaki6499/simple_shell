#include "stringwrapper.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - a function that prints a string
 * @str: input string
 */
void _puts(char *str)
{
	while (*str)
	{
		if (_putchar(*str++) == EOF)
			break;
	}
}
