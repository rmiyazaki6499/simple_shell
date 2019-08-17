#ifndef GLOBAL_H
#define GLOBAL_H

#include "environment.h"

/**
 * struct global_s - struct for  global variables
 * @env_head: pointer to environment linked list
 * @status: last exit status
 *
 * Description: global variable structure
 * for Simple Shell
 */
typedef struct global_s
{
	env_t *env_head;
	int status;
} global_t;

global_t *get_global(void);

#endif