#include "stringwrapper.h"
#include "stdlibwrapper.h"

/**
 * _strncmp - a function that compares two strings up to n bytes.
 * @s1: first string
 * @s2: second string
 * @n: bytes to compare
 * Return: value of comparison
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char t1, t2;

	while (n > 0)
	{
		t1 = (unsigned char) *s1++;
		t2 = (unsigned char) *s2++;
		if (t1 != t2)
			return (t1 - t2);
		if (t1 == '\0')
			return (0);
	}
	return (0);
}
