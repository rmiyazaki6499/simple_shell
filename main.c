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

env_t *env_head = NULL;

int main(void)
{
	ssize_t bytes_read;
	char *input;
	size_t input_length;
	char **child_program_argv;
	pid_t child_pid;
	str_ll *path_ll;
	int (*function)(char **name) = NULL;

	env_head = get_environment();
	path_ll = _strtoll(_getenv("PATH"), ":");

	while (1)
	{
		printf("$ ");

		input = NULL;
		input_length = 0;
		bytes_read = getline(&input, &input_length, stdin);
		if (bytes_read == -1)
		{
			free(input);
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
			function(child_program_argv + 1);

		child_program_argv[0] = _which(child_program_argv[0], path_ll);
		if (child_program_argv[0] == NULL)
		{
			frees(2, input, child_program_argv);
			perror(child_program_argv[0]);
			continue;
		}

		child_pid = fork();
		if (child_pid < 0)
		{
			perror("Error");
			free(input);
			free_linkedlist(path_ll);
			exit(1);
		}
		else if (child_pid == 0)
		{
			if (execve(child_program_argv[0], child_program_argv, NULL) == -1)
			{
				perror("Error");
				free(input);
				free_linkedlist(path_ll);
				exit(127);
			}
		}
		else
			wait(NULL);
		frees(3, input, child_program_argv[0], child_program_argv);
		input = NULL;
		input_length = 0;
	}

	free_linkedlist(path_ll);	

	return (EXIT_SUCCESS);
}
