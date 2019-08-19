#include "builtin.h"
#include "environment.h"
#include "stringwrapper.h"

/**
 * get_builtin_func - a function gets the builtin function.
 * @name: name of builtin function
 * Return: 0 on Succes, -1 on Failure
 */
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
		return (-1);
	for (i = 0; getbuiltin_func[i].func_name; i++)
	{
		if (_strcmp(name, getbuiltin_func[i].func_name) == 0)
			return (getbuiltin_func[i].function);
	}
	return (0);
}
