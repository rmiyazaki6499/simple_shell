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

str_ll *add_node_at_index(str_ll **head, const char *str, size_t index)
{
	str_ll *new_node = malloc(sizeof(str_ll)), *p = *head;

	if (new_node == NULL)
		return (NULL);

	new_node->string = _strdup(str);

	if (index == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	while (--index)
		p = p->next;

	new_node->next = p->next;
	p->next = new_node;

	return (new_node);
}

str_ll *_strtoll(char *str, char *delim)
{
	size_t length, delim_length;
	str_ll *node = NULL;

	delim_length = _strlen(delim);
	while (1)
	{
		while (_strncmp(str, delim, delim_length) == 0)
			str += delim_length;

		if (!*str)
			break;

		length = 0;
		while (str[length] && _strncmp(str + length, delim, delim_length) != 0)
			length++;

		add_node_end(&node, _strndup(str, length));
		str += length;
	}

	return (node);
}
