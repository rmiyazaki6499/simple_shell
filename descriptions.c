#include "builtin.h"
#include "stringwrapper.h"

/**
 * exit_description - a function that prints the description for exit.
 */
void exit_description(void)
{
	int i;
	char *description[] = {
		"exit: exit [n]",
		"    Exit the shell.",
		"",
		"    Exits the shell with a status of N.  If N is omitted, the exit status",
		"    is that of the last command executed.",
		NULL
	};

	for (i = 0; description[i] != NULL; i++)
	{
		_puts(description[i]);
		_puts("\n");
	}
}

/**
 * cd_description - a function that prints the description for exit.
 */
void cd_description(void)
{
	int i;
	char *description[] = {
		"cd: cd [dir]",
		"    Change the shell working directory.",
		"",
		"    Change the current directory to DIR.  The default DIR is the value of the",
		"    HOME shell variable.",
		"    The variable CDPATH defines the search path for the directory containing",
		"    DIR.  Alternative directory names in CDPATH are separated by a colon (:).",
		"    A null directory name is the same as the current directory.  If DIR begins",
		"    with a slash (/), then CDPATH is not used.",
		"",
		"    If the directory is not found, and the shell option `cdable_vars' is set,",
		"    the word is assumed to be  a variable name.  If that variable has a value,",
		"    its value is used for DIR.",
		"",
		"    Exit Status:",
		"    Returns 0 if the directory is changed, and if $PWD is set successfully whe",
		"n",
		NULL
	};

	for (i = 0; description[i] != NULL; i++)
	{
		_puts(description[i]);
		_puts("\n");
	}
}

/**
 * help_description - a function that prints the description for exit.
 */
void help_description(void)
{
	int i;
	char *description[] = {
		"help: help [pattern ...]",
		"    Display information about builtin commands.",
		"",
		"    Displays brief summaries of builtin commands.  If PATTERN is",
		"    specified, gives detailed help on all commands matching PATTERN,",
		"    otherwise the list of help topics is printed.",
		"    Arguments:",
		"      PATTERN	Pattern specifiying a help topic",
		"",
		"    Exit Status:",
		"    Returns success unless PATTERN is not found or an invalid option is given.",
		NULL
	};

	for (i = 0; description[i] != NULL; i++)
	{
		_puts(description[i]);
		_puts("\n");
	}
}

/**
 * setenv_description - a function that prints the description for exit.
 */
void setenv_description(void)
{
	int i;
	char *description[] = {
		"setenv: setenv [var] [myvalue]",
		"    define the value of environment variables.",
		"",
		"    If setenv is given no arguments, it displays all environment variables",
		"    and their values.",
		"    If only VAR is specified, it sets an environment variable of that name",
		"    to an empty (null) value.",
		"    If both VAR and VALUE are specified, it sets the variable named VAR to",
		"the value VALUE.",
		NULL
	};

	for (i = 0; description[i] != NULL; i++)
	{
		_puts(description[i]);
		_puts("\n");
	}
}

/**
 * unsetenv_description - a function that prints the description for exit.
 */
void unsetenv_description(void)
{
	int i;
	char *description[] = {
		"unsetenv: unsetenv [var]",
		"    remove an environment variable",
		"",
		"    The name argument points to a string, which is the name of the variable",
		"    to be removed.",
		"    The named argument shall not contain an '=' character.",
		"    If the named variable does not exist in the current environment, the",
		"    environment shall be unchanged and the function is considered to have",
		"completed successfully.",
		"",
		"    Exit Status:",
		"    Returns zero when successful, otherwise -1.",
		NULL
	};

	for (i = 0; description[i] != NULL; i++)
	{
		_puts(description[i]);
		_puts("\n");
	}
}
