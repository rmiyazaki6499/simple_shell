#include "builtin.h"
#include "stringwrapper.h"

/**
 * _help - a function that prints the description of a builtin.
 * @arguments: arguments from the command line
 * Return: 0 on Success, -1 on Failure
 */
int _help(char **arguments)
{
	int i;

	descriptions_t descriptions[] = {
		{"exit", exit_description},
		{"cd", cd_description},
		{"help", help_description},
		{"setenv", setenv_description},
		{"unsetenv", unsetenv_description},
		{NULL, NULL}
	};
	if (arguments[0]  == NULL)
		return (-1);

	for (i = 0; descriptions[i].func_name; i++)
	{
		if (_strcmp(arguments[0], descriptions[i].func_name) == 0)
			descriptions[i].description();
	}
	return (0);
}
