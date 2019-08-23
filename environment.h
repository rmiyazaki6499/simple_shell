#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "stdlibwrapper.h"
#include "linkedlist.h"

extern char **environ;

typedef struct env_s {
	char *name;
	char *value;
	struct env_s* next;
} env_t;

void free_env(env_t *head);
char *_getenv(const char *name);
env_t *get_environment(void);
str_ll *get_path(void);

#endif /* ENVIRONMENT_H */
