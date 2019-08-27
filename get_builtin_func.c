#include "builtin.h"
#include "environment.h"
#include "stringwrapper.h"

int (*get_builtin_func(char *name))(char **name)
{
	int i;

	builtin_func getbuiltin_func[] = {
		{"env", _printenv},
		{"cd", _cd},
		{"exit", exit_},
		{"help", _help},
		{NULL, NULL}
	};

	if (name == NULL)
		return (NULL);
	for (i = 0; getbuiltin_func[i].func_name; i++)
	{
		if (_strcmp(name, getbuiltin_func[i].func_name) == 0)
			return (getbuiltin_func[i].function);
	}
	return (NULL);
}
