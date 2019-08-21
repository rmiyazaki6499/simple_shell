#include "stringwrapper.h"
#include "stdlibwrapper.h"
#include "environment.h"
#include <unistd.h>

int _cd(char **arguments)
{
	int status;
	char *path;
	char *home;
	int free_path = 0;

	home = _getenv("HOME");

	if (!arguments || !arguments[0] || !arguments[0][0])
		path = home;
	else if (arguments[0][0] == '~')
	{
		path = malloc(sizeof(*path) * (_strlen(home) + _strlen(arguments[0])));
		if (!path)
			return (-1);
		free_path = 1;

		path = _strcpy(path, home);
		path = _strcat(path, arguments[0] + 1);
	}
	else
		path = arguments[0];

	status = chdir(path);

	if (free_path)
		free(path);

	return (status);
}
