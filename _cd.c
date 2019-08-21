#include "stringwrapper.h"
#include "stdlibwrapper.h"
#include "environment.h"
#include <unistd.h>

int _cd(char *argv[])
{
	int status;
	char *path;
	char *home;
	/* int free_path = 0; */

	home = _getenv("HOME");

	if (!argv || !argv[0] || !argv[0][0])
		path = home;
	else if (argv[0][0] == '~')
	{
		path = malloc(sizeof(*path) * (_strlen(home) + _strlen(argv[0]) - 1));
		if (!path)
			return (-1);

		path = _strcpy(path, home);
		path = _strcat(path, argv[0] + 1);
	}
	else
		path = argv[0];

	status = chdir(path);

	return (status);
}
