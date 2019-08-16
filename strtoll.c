#include "linkedlist.h"

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node = malloc(sizeof(list_t));
	list_t *last = *head;

	if (new_node == NULL)
		return (NULL);

	new_node->str  = strdup(str);
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	while (last->next != NULL)
		last = last->next;

	last->next = new_node;

	return (new_node);
}

str_ll strtoll(char *str, char delim)
{
	char *token = _strtok(path, delim);
	list_t *node = NULL;

	while (token != NULL)
	{
		if (!*token)
		{
			token = _strtok(NULL, delim);
			continue;
		}
		add_node_end(&node, token);
		token = _strtok(NULL, delim);
	}
	return (node);
}
