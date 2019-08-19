#ifndef BUILTIN_H
#define BUILTIN_H

#include <stdio.h>

extern int status;

/**
 * struct builtin_func_s - struct for builtin functions
 * @func_name: name of function
 * @function: function to be executed
 *
 * Description: struct for builtin functions
 * for simple shell
 */
typedef struct builtin_func_s
{
	char *func_name;
	int (*function)(char **);
} builtin_func;

/**
 * struct descriptions - struct for help descriptions
 * @func_name: name of function
 * @description: description for help
 *
 * Description: struct to manage all descriptions
 * for simple shell
 */
typedef struct descriptions_s
{
	char *func_name;
	void (*description)(void);
} descriptions_t;

int (*get_builtin_func(char *name))(char **name);

void exit_description(void);
void cd_description(void);
void help_description(void);
void setenv_description(void);
void unsetenv_description(void);

int _help(char **arguments);
int _cd(char **arguments);
int _printenv(char **arguments);
int exit_(char **arguments);

int _unsetenv(char **arguments);

#endif /* BUILTIN_H */
