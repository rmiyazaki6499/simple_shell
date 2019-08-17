#include "builtin.h"
#include "environment.h"

int (*get_builtin_func(char *name))(char **name)
{
	int i;

	builtin_func getbuiltin_func[] = {
		{"env", printenv},
		/*		{"exit", exit_function},
				{"cd", cd_function},
				{"alias", alias_function},
				{"help", help_function},
				*/		{NULL, NULL}
	};

	if (name == NULL)
		return (NULL);
	for (i = 0; getbuiltin_func[i].func_name; i++)
	{
		if (name == getbuiltin_func[i].func_name)
			return (getbuiltin_func[i].function);
	}
	return (NULL);
}
