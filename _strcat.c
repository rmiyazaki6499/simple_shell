#include "stringwrapper.h"

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
