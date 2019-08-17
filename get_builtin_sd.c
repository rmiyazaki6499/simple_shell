#include "builtin.h"

char *get_builtin_sd(char *name)
{
	int i;

	builtin_sd getbuiltin_sd[] = {
		/* {"exit", short_description},
		 * {"cd", short_description},
		 * {"alias", short_description},
		 * {"help", short_description},
		 */              {NULL, NULL}
	};

	if (name == NULL)
		return (NULL);                                                        for (i = 0; getbuiltin_sd[i].func_name; i++)
		{                                                                                     if (name == getbuiltin_sd[i].func_name)
			return (getbuiltin_sd[i].short_description);
		}
	return (NULL);
}
