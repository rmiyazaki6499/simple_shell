#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "stdlibwrapper.h"

extern char **environ;

typedef struct env_s {
	char *name;
	char *value;
	struct env_s* next;
} env_t;

extern env_t *env_head;

void free_env(env_t *head);
char *_getenv(const char *name);
env_t *get_environment(void);

#endif /* ENVIRONMENT_H */
