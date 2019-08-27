#include "environment.h"
#include "stringwrapper.h"
#include "global.h"
#include <stdio.h>

/**
 * _printenv - a function that prints the environment variables
 * @arguments: environment variables
 * Return: 0 on Success, -1 if failed
 */
int _printenv(char **arguments)
{
	const env_t *current_node = global()->env_head;
	(void) arguments;

	if (!current_node)
		return (-1);

	while (current_node != NULL)
	{
		_puts(current_node->name);
		_puts("=");
		_puts(current_node->value);
		current_node = current_node->next;
	}
	return (0);
}
