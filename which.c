#include "linkedlist.h"
#include "stringwrapper.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

/**
 * _which - a function that takes a command and returns a path.
 * @cmd: input command
 * @head: pointer to head node of str_ll
 * Return: pointer to string
 */
char *_which(char *cmd, str_ll *head)
{
	size_t cmd_length;
	char *check_pointer, *current_string;
	struct stat st;

	if (cmd[0] == '/' && stat(cmd, &st) == 0)
		return (_strdup(cmd));

	cmd_length = _strlen(cmd);

	while (head)
	{
		current_string = (_strcmp(head->string, ".") == 0)
			? getcwd(NULL, 0) : _strdup(head->string);

		check_pointer = malloc(_strlen(current_string) + cmd_length + 2);

		_strcpy(check_pointer, current_string);
		free(current_string);
		_strcat(check_pointer, "/");
		_strcat(check_pointer, cmd);

		if (stat(check_pointer, &st) == 0)
			return (check_pointer);

		free(check_pointer);
		head = head->next;
	}
	return (NULL);
}
