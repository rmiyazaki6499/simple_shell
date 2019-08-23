#ifndef BUILTIN_H
#define BUILTIN_H

#include <stdio.h>

extern int status;

typedef struct builtin_func_t
{
	char *func_name;
	int (*function)(char **);
	struct builtin_t_ *next;
} builtin_func;

typedef struct builtin_ld_t
{
	char *func_name;
	char **long_description;
	struct builtin_t_ *next;
} builtin_ld;

typedef struct builtin_sd_t
{
	char *func_name;
	char *short_description;
	struct builtin_t_ *next;
} builtin_sd;

int (*get_builtin_func(char *name))(char **name);
char **get_builtin_ld(char *name);
char *get_builtin_sd(char *name);

int _cd(char **arguments);
int _printenv(char **arguments);
int exit_(char** arguments);

#endif /* BUILTIN_H */
