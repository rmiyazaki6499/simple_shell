#include "linkedlist.h"
#include "stringwrapper.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

char *_which(char *cmd, str_ll *head)
{
	size_t cmd_length, str_length;
	char *check_pointer;
	struct stat st;

	if (stat(cmd, &st) == 0)
		return (_strdup(cmd));

	cmd_length = _strlen(cmd);

	while (head)
	{
		str_length = _strlen(head->string);
		check_pointer = malloc(str_length + cmd_length + 2);
		_strcpy(check_pointer, head->string);
		_strcat(check_pointer, "/");
		_strcat(check_pointer, cmd);
		if (stat(check_pointer, &st) == 0)
		{
			return (check_pointer);
		}
		free(check_pointer);
		head = head->next;
	}
	return(NULL);
}
