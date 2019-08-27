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
	char t1, t2;

	while (n--)
	{
		t1 = *s1++;
		t2 = *s2++;
		if (t1 != t2 || t1 == '\0' || t2 == '\0')
			return (t1 - t2);
	}
	return (0);
}
