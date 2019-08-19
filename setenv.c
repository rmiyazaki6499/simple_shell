#include "builtin.h"
#include "environment.h"
#include "stringwrapper.h"
#include "global.h"

env_t *add_env_node(env_t **head, char *name, char *value);

/**
 * _setenv - a function sets the environment variable.
 * @arguments: arguments from command line
 * Return: 0 on Success
 */
int _setenv(char **arguments)
{
	env_t *head = global()->env_head;
	char *value;

	if (!arguments[0])
	{
		_printenv(arguments);
		return (0);
	}

	if (arguments[1] != NULL)
		value = arguments[1];
	else
		value = "";

	while (head != NULL)
	{
		if (_strcmp(head->name, arguments[0]) == 0)
		{
			free(head->value);
			head->value = _strdup(value);
			return (0);
		}
		head = head->next;
	}
	add_env_node(&(global()->env_head), _strdup(arguments[0]), _strdup(value));
	return (0);
}
