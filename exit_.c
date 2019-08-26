#include "builtin.h"
#include <stdlib.h>
#include <unistd.h>
#include "global.h"

int _atoi(char *);

/**
 * is_number - a function that checks if a character is a number.
 * @s: string
 * Return: 1 if character is a number, 0 if not
 */
int is_number(char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}

	return (1);
}

/**
 * exit_ - a function that exits a program.
 * @arguments: input arguments
 * Return: exit status
 */
int exit_(char **arguments)
{
	if (arguments[0] == NULL)
		exit(WEXITSTATUS(get_global()->status));
	else if (is_number(arguments[0]))
		exit(_atoi(arguments[0]));
	else
	{
		puts("Bad input");
	}
}
