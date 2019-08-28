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
	char *check_pointer, *current_string, *hs;
	struct stat st;

	if (cmd[0] == '/' && stat(cmd, &st) == 0)
		return (_strdup(cmd));

	if (cmd[0] == '.' && cmd[1] == '/' && stat(cmd, &st) == 0)
		return (_strdup(cmd));

	if (cmd[0] == '.' && cmd[1] == '.' && stat(cmd, &st) == 0)
		return (_strdup(cmd));

	cmd_length = _strlen(cmd);

	while (1)
	{
		hs = head ? head->string : ".";
		current_string = (_strcmp(hs, ".") == 0)
			? getcwd(NULL, 0) : _strdup(hs);

		check_pointer = malloc(_strlen(current_string) + cmd_length + 2);

		_strcpy(check_pointer, current_string);
		free(current_string);
		_strcat(check_pointer, "/");
		_strcat(check_pointer, cmd);

		if (stat(check_pointer, &st) == 0)
			return (check_pointer);

		free(check_pointer);
		if (!head || !head->next)
			break;
		head = head->next;
	}
	return (NULL);
}
