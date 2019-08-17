#include "environment.h"
#include "global.h"
#include <stdio.h>

int _printenv(char **arguments)
{
	const env_t *current_node = get_global()->env_head;

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
