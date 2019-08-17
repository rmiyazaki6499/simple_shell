#include "environment.h"

int printenv(const env_t *head)
{
	const env_t *current_node = head;

	if (!head)
		return (-1);

	while (current_node != NULL)
	{
		printf("%s=%s\n", current_node->name, current_node->value);
		current_node = current_node->next;
	}
	return (0);
}
