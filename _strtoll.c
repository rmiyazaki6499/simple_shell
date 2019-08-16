#include "linkedlist.h"
#include "stringwrapper.h"

str_ll *add_node_end(str_ll **head, const char *str)
{
	str_ll *new_node = malloc(sizeof(str_ll));
	str_ll *last = *head;

	if (new_node == NULL)
		return (NULL);

	new_node->string  = _strdup(str);
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

str_ll *_strtoll(char *str, char *delim)
{
	char *token = _strtok(str, delim);
	str_ll *node = NULL;

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
