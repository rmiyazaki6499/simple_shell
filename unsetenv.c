#include "builtin.h"
#include "environment.h"
#include "stringwrapper.h"
#include "global.h"

/**
 * delete_nodeint_at_index - a function that deletes the node
 * at index index of a listint_t linked list
 * @head: head node
 * @index: index of deleted node
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(env_t **head, unsigned int index)
{
	unsigned int i;
	env_t *temp_node;
	env_t *next_node;

	if (!*head || !head)
		return (-1);

	temp_node = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp_node);
		return (1);
	}
	for (i = 0; i < (index - 1); i++)
	{
		if (temp_node == NULL)
			return (-1);
		temp_node = temp_node->next;
	}
	next_node = temp_node->next;
	temp_node->next = temp_node->next->next;
	free(next_node);

	return (1);
}

/**
 * _unsetenv - function deletes the variable name from  the  environment.
 * @arguments: arguments from the command line
 * Return: 1 if it succeeded, -1 if it failed
 */
int _unsetenv(char **arguments)
{
	env_t *head = global()->env_head;
	unsigned int count = 0;

	if (!arguments[0])
		return (-1);

	while (head != NULL)
	{
		if (_strcmp(head->name, arguments[0]) == 0)
			break;
		count += 1;
		head = head->next;
	}
	delete_nodeint_at_index(&(global()->env_head), count);

	return (-1);
}
