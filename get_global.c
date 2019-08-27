#include "stdlibwrapper.h"
#include "global.h"

/**
 * get_global - a function that gets the global variable.
 * Return: global variable
 */
global_t *global(void)
{
	static global_t global = {
		NULL,
		0,
		NULL,
		NULL,
		NULL,
		0,
		NULL
	};

	return (&global);
}
