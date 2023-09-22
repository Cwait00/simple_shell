#include "maint_shell.h"

/**
 * _memset - to fill a block of memory with specified byte value.
 * @s: the pointer to the memory area that needs to be filled.
 * @b: the byte value to fill the memory area with
 * @n: the num of bytes to be filled
 * Return: (s) a pointer to the memory area s
 * after filling it with the specified byte b.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int h;

	for (h = 0; h < n; h++)
		s[h] = b;
	return (s);
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - a block of memory reallocates
 * @ptr: A pointer to previous mallocated block
 * @old_size: byte size of prior block
 * @new_size: byte size of new block
 * Return: pointer to the old block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
