#include "main.h"
/**
 * _strspn - gets the length of a prefix substring
 * @s: initial segment
 * @accept: consists of bytes
 * Return: number of bytes
 */
unsigned int _strspn(char *s, char *accept)
{
	int x = 0, y, z;

	for (y = 0; s[y] != '\0'; y++)
	{
		if (s[y] != 32)
		{
			for (z = 0; accept[z] != '\0'; z++)
			{
				if (s[y] == accept[z])
					x++;
			}
		}
		else
			return (x);
	}
	return (x);
}
