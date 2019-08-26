#include "stdlibwrapper.h"

/**
 * _realloc - a function that reallocates a memory block using malloc and free
 * @ptr: pointer to originally malloced memory
 * @orig_length: old size of memory
 * @new_length: new size of memory
 * Return: a pointer to the memory previously allocated with a call to malloc
 */
void *_realloc(void *ptr, size_t orig_length, size_t new_length)
{
	void *new_ptr;

	if (new_length == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (!ptr)
		return (malloc(new_length));

	new_ptr = malloc(new_length);

	if (new_ptr)
	{
		_memcpy(new_ptr, ptr, orig_length);
		free(ptr);
	}
	return (new_ptr);
}
