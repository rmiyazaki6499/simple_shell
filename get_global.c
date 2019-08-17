#include "stdlibwrapper.h"
#include "global.h"

/**
 * get_global - a function that gets the global variable.
 * Return: global variable
 */
global_t *get_global(void)
{
	static global_t global = {
		NULL,
		0
	};

	return (&global);
}
