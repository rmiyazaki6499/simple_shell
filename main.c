#include "stringwrapper.h"
#include "linkedlist.h"
#include "inputhelper.h"
#include "environment.h"
#include "builtin.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "global.h"

int main(void)
{
	ssize_t bytes_read;
	char *input, *child_program_name;
	size_t input_length;
	char **child_program_argv;
	pid_t child_pid;
	str_ll *path_ll;
	int (*function)(char **name) = NULL;

	get_global()->env_head = get_environment();
	path_ll = get_path();

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_puts("$ ");

		input = NULL;
		input_length = 0;
		bytes_read = getline(&input, &input_length, stdin);
		if (bytes_read == -1)
		{
			free(input);
			if (isatty(STDIN_FILENO))
				putchar('\n');
			break;
		}
		input[bytes_read - 1] = '\0';

		child_program_argv = strtow(input, " ");
		if (!child_program_argv)
		{
			free(input);
			continue;
		}

		function = get_builtin_func(child_program_argv[0]);
		if (function)
		{
			function(child_program_argv + 1);
			frees(2, input, child_program_argv);
			continue;
		}

		child_program_name = _which(child_program_argv[0], path_ll);
		if (child_program_name == NULL)
		{
			perror(child_program_name);
			frees(2, input, child_program_argv);
			continue;
		}
		child_program_argv[0] = child_program_name;

		child_pid = fork();
		if (child_pid < 0)
		{
			perror("Error");
			frees(3, input, child_program_name, child_program_argv);
			free_linkedlist(path_ll);
			free_env(get_global()->env_head);
			exit(1);
		}
		else if (child_pid == 0)
		{
			if (execve(child_program_argv[0], child_program_argv, environ) == -1)
			{
				perror("Error");
				frees(3, input, child_program_name, child_program_argv);
				free_linkedlist(path_ll);
				free_env(get_global()->env_head);
				exit(127);
			}
		}
		else
			wait(&(get_global()->status));

		frees(3, input, child_program_name, child_program_argv);
	}
	free(child_program_argv);
	free_env(get_global()->env_head);
	free_linkedlist(path_ll);

	return (EXIT_SUCCESS);
}
