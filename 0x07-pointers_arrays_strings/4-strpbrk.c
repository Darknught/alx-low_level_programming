#include "main.h"
/**
 * _strpbrk - searches a string for any of a sets of bytes
 * @s: first occurence
 * @accept: bytes in string
 * Return: pointer in bytes s
 */
char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s)
	{
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
				return (s);
		}
		s++;
	}
	return (NULL);
}
