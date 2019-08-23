#include "stdlibwrapper.h"
#include "global.h"

global_t *get_global(void)
{
	static global_t global = {
		NULL,
		0
	};

	return (&global);
}
