#ifndef STDLIBWRAPPER_H
#define STDLIBWRAPPER_H

#include <stdlib.h>
#include <stdarg.h>

void frees(size_t n, ...);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, size_t orig_length, size_t new_length);

#endif
