#ifndef BUILTIN_H
#define BUILTIN_H

#include <stdio.h>

extern int status;

/**
 * struct str_ll_s - linked list
 * @string: malloc'ed string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for simple shell
 */
typedef struct builtin_func_t
{
	char *func_name;
	int (*function)(char **);
} builtin_func;

/**
 * struct str_ll_s - linked list
 * @string: malloc'ed string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for simple shell
 */
typedef struct builtin_sd_t
{
	char *func_name;
	char *short_description;
} builtin_sd;

int (*get_builtin_func(char *name))(char **name);
char *print_d(char *name);

int _cd(char **arguments);
int _printenv(char **arguments);
int exit_(char **arguments);

#endif /* BUILTIN_H */
