#include "stdlibwrapper.h"

/**
 * frees - a function that frees multiple memory allocations.
 * @n: number of arguments
 * Return: void
 */
void frees(size_t n, ...)
{
	va_list valist;

	va_start(valist, n);

	while (n--)
		free(va_arg(valist, void *));

	va_end(valist);
}
