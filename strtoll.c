#include "linkedlist.h"

str_ll *add_node_end(str_ll **head, const char *str)
{
	str_ll *new_node = malloc(sizeof(list_t));
	str_ll *last = *head;

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

str_ll *strtoll(char *str, char *delim)
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
