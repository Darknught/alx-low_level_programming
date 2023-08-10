#include "main.h"
#include <stdlib.h>
/**
 * string_nconcat - concatenates two strings
 * @s1: destination string
 * @s2: source string
 * @n: integer
 * Return: pointer
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *result;
	unsigned int i, j, k;

	if (s1 == NULL)
	{
		i = 0;
	}
	else
	{
		for (i = 0; s1[i]; ++i)
			;
	}
	if (s2 == NULL)
	{
		j = 0;
	}
	else
	{
		for (j = 0; s2[j]; ++j)
			;
	}
	if (j > n)
		j = n;
	result = malloc(sizeof(char) * (i + j + 1));

	if (result == NULL)
		return (NULL);
	for (k = 0; k < i; k++)
		result[k] = s1[k];
	result[i + j] = '\0';
	return (result);
}
