#include "main.h"
/**
 * _strncat - concatinates two strings
 * @src: string source
 * @dest: string destination
 * @n: size of the int
 * Return: resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	{
		continue;
	}

	for (j = 0; src[j] != '\0' && j < n; j++)
	{
		dest[1 + j] = src[j];
	}
	dest[1 + j] = '\0';
	return (dest);
}
