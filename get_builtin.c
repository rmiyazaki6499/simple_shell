#include "builtin.h"

int (*get_builtin(char *name))
{
	int i;

	builtini_t getbuiltin[] = {
/*		{"exit", exit_function, long_description, short_description},
		{"cd", cd_function, long_description, short_description},
		{"alias", alias_function, long_description, short_description},
		{"help", help_function, long_description, short_description},
*/		{NULL, NULL, NULL, NULL}
	};

	if (name == NULL)
		return (NULL);
	for (i = 0; getbuiltin[i].func_name; i++)
	{
		if (name == getbuiltin[i])
			return (getbuiltin[i]);
	}
	return (NULL);
}
