#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "stdlibwrapper.h"
#include "linkedlist.h"

extern char **environ;

/**
 * struct env_s - linked list of environments
 * @name: name of environment variable
 * @value: value of environment variable
 * @next: points to the next node
 *
 * Description: linked list node structure
 * for simple shell
 */
typedef struct env_s
{
	char *name;
	char *value;
	struct env_s *next;
} env_t;

void free_env(env_t *head);
char *_getenv(const char *name);
env_t *get_environment(void);
str_ll *get_path(void);

int delete_nodeint_at_index(env_t **head, unsigned int index);

#endif /* ENVIRONMENT_H */
