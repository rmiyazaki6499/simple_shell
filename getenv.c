#include "environment.h"
#include "stringwrapper.h"
#include "linkedlist.h"

char *_getenv(const char *name)
{
	size_t env_length, i;

	if (!environ || !name)
		return (NULL);

	env_length = _strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if ((_strncmp(environ[i], name, env_length) == 0) && (environ[i][env_length] == '='))
			return (environ[i] + env_length + 1);
	}
	return (NULL);
}
