#ifndef GLOBAL_H
#define GLOBAL_H

#include "environment.h"

typedef struct global_s {
	env_t *env_head;
	int status;
} global_t;

global_t *get_global(void);

#endif
