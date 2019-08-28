#include "stringwrapper.h"
#include "linkedlist.h"
#include "inputhelper.h"
#include "environment.h"
#include "builtin.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "stdlibwrapper.h"
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
 */
void handle_fork(pid_t child_pid, char *child_name)
{
	if (child_pid < 0)
	{
		perror("Error");
		frees(2, global()->input, child_name);
		exit(1);
	}
	else if (child_pid == 0)
	{
		if (execve(child_name, global()->child_argv, environ) == -1)
		{
			perror("Error");
			global()->status = 126;
			frees(3, global()->input, child_name, global()->child_argv);
			exit(126);
		}
	}
	else
		wait(&(global()->status));
}

/**
 * on_make - setup things
 */
/*
 *void on_make(void) __attribute__ ((constructor));
 *void on_make(void)
 *{
 *signal(SIGINT, sigint_handler);

 *global()->env_head = get_environment();
 *global()->path_ll = get_path();
 *}
 */
/**
 * destruct - free some global variables
 */
/*
 *void destruct(void) __attribute__ ((destructor));
 *void destruct(void)
 *{
 *	free_env(global()->env_head);
 *	free_linkedlist(global()->path_ll);
 *	if (global()->previous)
 *		free(global()->previous);
 *}
 */
/**
 * main - entry point for shell program
 * @argc: argument count
 * @argv: arguments
 * Return: EXIT_SUCCESS on success, else an error code
 */
int main(int argc, char *argv[])
{
	ssize_t bytes_read;
	char *child_name;
	size_t input_length;
	pid_t child_pid;
	int (*function)(char **name) = NULL;
	(void) argc;

	signal(SIGINT, sigint_handler);

	global()->env_head = get_environment();
	global()->path_ll = get_path();

	while (1)
	{
		(global()->command_number)++;
		if (isatty(STDIN_FILENO))
			_puts("$ ");

		global()->input = NULL;
		input_length = 0;
		bytes_read = getline(&(global()->input), &input_length, stdin);
		if (bytes_read == -1)
		{
			free(global()->input);
			if (isatty(STDIN_FILENO))
				putchar('\n');
			return (global()->status);
		}
		(global()->input)[bytes_read - 1] = '\0';

		global()->child_argv = strtow(global()->input, " ");
		if (!global()->child_argv)
		{
			frees(2, global()->input, global()->child_argv);
			continue;
		}

		function = get_builtin_func(global()->child_argv[0]);
		if (function)
		{
			function(global()->child_argv + 1);
			frees(2, global()->input, global()->child_argv);
			continue;
		}

		child_name = _which(global()->child_argv[0], global()->path_ll);
		if (child_name == NULL)
		{
			global()->status = 127;
			print_error(argv[0]);
			frees(2, global()->input, global()->child_argv);
			continue;
		}
		else if (access(child_name, X_OK) != 0)
		{
			global()->status = 126;
			print_error(argv[0]);
			frees(3, global()->input, child_name, global()->child_argv);
			continue;
		}
		child_pid = fork();
		handle_fork(child_pid, child_name);
		frees(3, global()->input, child_name, global()->child_argv);
	}
	return (global()->status);
}
