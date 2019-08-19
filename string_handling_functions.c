#include "stringwrapper.h"
#include "stdlibwrapper.h"

/**
 * _strlen - a function that returns the length of a string.
 * @s: input string
 * Return: length of string
 */
size_t _strlen(const char *s)
{
	const char *p = s;

	while (*s)
		++s;
	return (s - p);
}

/**
 * _strcmp - a function that compares two strings.
 * @s1: first string
 * @s2: second string
 * Return: value of comparison
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
		s1++, s2++;
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}
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

/**
 * *_strcat - a function that concatenates two strings.
 * @dest: first string
 * @src: appended string
 * Return: the resulting string with src appended to dest
 */
char *_strcat(char *dest, const char *src)
{
	int length, i;

	for (length = 0; dest[length] != '\0'; length++)
		;
	for (i = 0; src[i] != '\0'; i++)
		dest[length + i] = src[i];
	dest[length + i] = '\0';
	return (dest);
}
