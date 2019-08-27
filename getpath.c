#include "environment.h"

str_ll *get_path(void)
{
	str_ll *head = NULL;
	char *path_str = _getenv("PATH"), *start;
	int add_current_dir = 0, index = -1;

	start = path_str;
	if (*start == ':')
	{
		add_current_dir = 1;
		index = 0;
	}
	else
	{
		index = 0;
		while (*start)
		{
			if (*start == ':')
			{
				index++;
				if (*(start + 1) == ':' || *(start + 1) == '\0')
				{
					add_current_dir = 1;
					break;
				}
			}
			start++;
		}
	}

	head = _strtoll(path_str, ":");
	if (add_current_dir && index > -1)
		add_node_at_index(&head, "./", index);

	return (head);
}
