#include "linkedlist.h"
#include "stringwrapper.h"
#include "environment.h"

/**
 * add_env_node - a function that adds a new env node.
 * @head: the first node
 * @name: name of new env variable
 * @value: value of new env variable
 * Return: pointer to head of node
 */
env_t *add_env_node(env_t **head, char *name, char *value)
{
	env_t *new, *p;

	if (!head)
		return (NULL);

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);

	new->name = name;
	new->value = value;
	new->next = NULL;

	if (!*head)
	{
		*head = new;
		return (new);
	}

	p = *head;
	while (p->next)
		p = p->next;

	p->next = new;
	return (new);
}

/**
 * get_environment - a function that gets environment from environ.
 * Return: head of environment linked list
 */
env_t *get_environment(void)
{
	env_t *head = NULL;
	char *name, *value;
	size_t name_len;
	char **env_cpy = environ;

	if (!env_cpy)
		return (NULL);

	while (*env_cpy)
	{
		name_len = 0;
		while ((*env_cpy)[name_len] && (*env_cpy)[name_len] != '=')
			name_len++;

		name = _strndup(*env_cpy, name_len);
		if (!name)
		{
			free_env(head);
			return (NULL);
		}

		value = _strndup(*env_cpy + name_len + 1, _strlen(*env_cpy));
		if (!value)
		{
			free(name);
			free_env(head);
			return (NULL);
		}

		add_env_node(&head, name, value);
		env_cpy++;
	}

	return (head);
}

/**
 * free_env - a function that frees environment linked list.
 * @head: head node of environment linked list
 */
void free_env(env_t *head)
{
	if (!head)
		return;

	free_env(head->next);

	free(head->name);
	free(head->value);
	free(head);
}
