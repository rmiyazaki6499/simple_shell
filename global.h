#ifndef GLOBAL_H
#define GLOBAL_H

#include "environment.h"
#include "linkedlist.h"

/**
 * struct global_s - struct for  global variables
 * @env_head: pointer to environment linked list
 * @status: last exit status
 * @input: input from command line
 * @path_ll: pointer to struct path_ll
 * @child_argv: arguments from child process
 * @command_number: number of commands made
 * @previous: previous
 *
 * Description: global variable structure
 * for Simple Shell
 */
typedef struct global_s
{
	env_t *env_head;
	int status;
	char *input;
	str_ll *path_ll;
	char **child_argv;
	size_t command_number;
	char *previous;
} global_t;

global_t *global(void);

#endif
