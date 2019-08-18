#include "environment.h"
#include "stringwrapper.h"
#include "linkedlist.h"
#include "global.h"

/**
 * _getenv - a function gets and environment variable.
 * @name: name of environment variable
 * Return: pointer to environment variable
 */
char *_getenv(const char *name)
{
	size_t env_length;
	env_t *ep = get_global()->env_head;

	if (!ep || !name)
		return (NULL);

	env_length = _strlen(name);

	for (; ep != NULL; ep = ep->next)
	{
		if (_strncmp(ep->name, name, env_length) == 0)
			return (ep->value);
	}
	return (NULL);
}
