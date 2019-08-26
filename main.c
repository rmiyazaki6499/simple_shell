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
#include <signal.h>

/**
 * sigint_handler - handle SIGINT signal
 * @signum: Number of the signal to handle
 */
void sigint_handler(int signum)
{
	(void) signum;

	if (isatty(STDIN_FILENO))
		_puts("\n$ ");
}

/**
 * handle_fork - handle the different paths a fork may take
 * @child_pid: pid of the child after a fork
 * @child_name: path to child exectuable program
 * @child_argv: arguments for the child program
 */
void handle_fork(pid_t child_pid, char *child_name, char **child_argv)
{
	if (child_pid < 0)
	{
		perror("Error");
		frees(3, get_global()->input, child_name, child_argv);
		free_linkedlist(get_global()->path_ll);
		free_env(get_global()->env_head);
		exit(1);
	}
	else if (child_pid == 0)
	{
		if (execve(child_name, child_argv, environ) == -1)
		{
			perror("Error");
			frees(3, get_global()->input, child_name, child_argv);
			free_linkedlist(get_global()->path_ll);
			free_env(get_global()->env_head);
			exit(127);
		}
	}
	else
		wait(&(get_global()->status));
}

/**
 * on_make - setup things
 */
void on_make(void) __attribute__ ((constructor));
void on_make(void)
{
	signal(SIGINT, sigint_handler);

	get_global()->env_head = get_environment();
	get_global()->path_ll = get_path();
}

/**
 * destruct - free some global variables
 */
void destruct(void) __attribute__ ((destructor));
void destruct(void)
{
	free_env(get_global()->env_head);
	free_linkedlist(get_global()->path_ll);
}

/**
 * main - entry point for shell program
 *
 * Return: EXIT_SUCCESS on success, else an error code
 */
int main(void)
{
	ssize_t bytes_read;
	char *child_name;
	size_t input_length;
	char **child_argv;
	pid_t child_pid;
	int (*function)(char **name) = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_puts("$ ");

		get_global()->input = NULL;
		input_length = 0;
		bytes_read = getline(&(get_global()->input), &input_length, stdin);
		if (bytes_read == -1)
		{
			free(get_global()->input);
			if (isatty(STDIN_FILENO))
				putchar('\n');
			break;
		}
		(get_global()->input)[bytes_read - 1] = '\0';

		child_argv = strtow(get_global()->input, " ");
		if (!child_argv)
		{
			free(get_global()->input);
			continue;
		}

		function = get_builtin_func(child_argv[0]);
		if (function)
		{
			function(child_argv + 1);
			frees(2, get_global()->input, child_argv);
			continue;
		}

		child_name = _which(child_argv[0], get_global()->path_ll);
		if (child_name == NULL)
		{
			perror(child_name);
			frees(2, get_global()->input, child_argv);
			continue;
		}

		child_pid = fork();
		handle_fork(child_pid, child_name, child_argv);

		frees(3, get_global()->input, child_name, child_argv);
	}

	return (EXIT_SUCCESS);
}
