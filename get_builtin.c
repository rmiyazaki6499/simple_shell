#include "builtin.h"

int (*get_builtin(char *format))(char *format, va_list)
{
	int i;

	builtin getfunction[] = {
/*		{"exit", exit_function, long_description, short_description},
		{"cd", cd_function, long_description, short_description},
		{"alias", alias_function, long_description, short_description},
		{"help", help_function, long_description, short_description},
*/		{NULL, NULL, NULL, NULL}
	};

	if (format[1] == ' ' || format[1] == '\0')
		return (NULL);
	for (i = 0; getfn[i].specifier; i++)
	{
		if (format[1] == getfn[i].specifier[1])
			return (getfn[i].fn);
	}
	return (NULL);
}
