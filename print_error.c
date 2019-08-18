#include "stringwrapper.h"

void print_error(char *argument)
{
	_puts(argument);
	_print_number(get_global()->command_number);
	_puts(": ");
	_puts(get_global()->child_argv[0]);
	_puts(": not found");
}
