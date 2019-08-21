#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

extern char **environ;

typedef struct env_s {
	char *name;
	char *value;
	struct env_s* next;
} env_t;

char *_getenv(const char *name);
env_t *get_environment(void);

#endif /* ENVIRONMENT_H */
