#include "environment.h"
#include "stringwrapper.h"
#include "linkedlist.h"

char *_getenv(const char *name)
{
	size_t env_length, i;
	env_t *ep = env_head;

	if (!ep || !name)
		return (NULL);

	env_length = _strlen(name);

	for (; ep != NULL; ep = ep->next)
	{
		puts(ep->value);
		if (_strncmp(ep->name, name, env_length) == 0)
			return (ep->value);
	}
	return (NULL);
}
