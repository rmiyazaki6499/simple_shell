#include "builtin.h"

char **get_builtin_ld(char *name)
{
	int i;

	builtin_ld getbuiltin_ld[] = {
		/* {"exit", long_description},
		 * {"cd", long_description},
		 * {"alias", long_description},
		 * {"help", long_description},
		 *                                                              */              {NULL, NULL}
	};

	if (name == NULL)
		return (NULL);
	for (i = 0; getbuiltin_ld[i].func_name; i++)
	{
		if (name == getbuiltin_ld[i].func_name)
			return (getbuiltin_ld[i].long_description);
	}
	return (NULL);
}
