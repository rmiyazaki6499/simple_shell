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
		printf("%s=%s\n", current_node->name, current_node->value);
		current_node = current_node->next;
	}
	return (0);
}
