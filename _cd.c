#include "stringwrapper.h"
#include "stdlibwrapper.h"
#include "environment.h"
#include <unistd.h>
#include "global.h"

/**
 * _cd - a function that changes the directory.
 * @arguments: input arguments
 * Return: status
 */
int _cd(char **arguments)
{
	int status;
	char *path, *home, *temp_previous;
	int free_path = 0;

	if (!global()->previous)
		global()->previous = getcwd(NULL, 0);
	home = _getenv("HOME");
	if (!arguments || !arguments[0] || !arguments[0][0])
		path = _strdup(home);
	else if (arguments[0][0] == '~')
	{
		path = malloc(sizeof(*path) * (_strlen(home) + _strlen(arguments[0])));
		if (!path)
			return (-1);
		free_path = 1;

		path = _strcpy(path, home);
		path = _strcat(path, arguments[0] + 1);
	}
	else if (_strcmp(arguments[0], "-") == 0)
	{
		path = _strdup(global()->previous);
		_puts(path);
		_puts("\n");
	}
	else
		path = _strdup(arguments[0]);

	temp_previous = getcwd(NULL, 0);
	status = chdir(path);
	if (status == 0)
	{
		free(global()->previous);
		global()->previous = temp_previous;
	}
	else
		free(temp_previous);
	free(path);
	return (status);
}
