#include "main.h"
#include <stdlib.h>
/**
 * _realloc - reallocates memory block
 * @ptr: pointer to the previous memory
 * @old_size: size in bytes for allocated space
 * @new_size: size in bytes of the new memory
 * Return: pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	unsigned int i = 0;
	unsigned int n = new_size;
	char *old = ptr;

	if (ptr == NULL)
	{
		p = malloc(new_size);
		return (p);
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size == old_size)
		return (ptr);
	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	if (new_size > old_size)
		n = old_size;
	while (i < n)
	{
		p[i] = old[i];
		i++;
	}
	free(ptr);
	return (p);
}
