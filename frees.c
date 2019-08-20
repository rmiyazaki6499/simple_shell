#include "stdlibwrapper.h"

void frees(size_t n, ...)
{
	va_list valist;
	va_start(valist, n);

	while (n--)
		free(va_arg(valist, void *));

	va_end(valist);
}
