#include "main.h"
#include <stdlib.h>
/**
 * _calloc - allocates memory for an array using malloc
 * @nmemb: integer array
 * @size: array size
 * Return: pointer to the allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int total_size = nmemb * size;
	unsigned int i;

	if (nmemb != 0 && total_size / nmemb != size)
	{
		return (NULL);
	}
	ptr = malloc(total_size);

	if (ptr != NULL)
	{
		unsigned char *byte_ptr = (unsigned char *)ptr;

		for (i = 0; i < total_size; i++)
		{
			byte_ptr[i] = 0;
		}
	}
	return (ptr);
}
