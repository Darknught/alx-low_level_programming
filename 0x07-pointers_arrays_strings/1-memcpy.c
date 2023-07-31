#include "main.h"
/**
 * _memcpy - copies memory area
 * @dest: First memory area
 * @src: Second memory area
 * @n: bytes
 * Return: dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n && *(src + i); i++)
	{
		*(dest + i) = *(src + i);
	}

	return (dest);
}
