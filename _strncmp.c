#include "stringwrapper.h"
int _strncmp(const char *s1, const char *s2, size_t n)
{
	return (strncmp(s1, s2, n));
}
