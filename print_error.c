#include "stringwrapper.h"
#include "global.h"

void print_error(char *argument)
{
	_puts(argument);
	_puts(": ");
	_print_number(global()->command_number);
	_puts(": ");
	_puts(global()->child_argv[0]);
	if (global()->status == 126)
		_puts(": Permission denied\n");
	else if (global()->status == 127)
		_puts(": not found\n");
}
