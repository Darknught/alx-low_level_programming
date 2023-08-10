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
	unsigned int i, j;
	unsigned int len1 = 0;
	unsigned int len2 = 0;
	unsigned int total_len = len1 + n;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
		s2 = "";
	while (s1[len1] != '\0')
		len1++;
	if (s2 != NULL)
	{
		while (s2[len2] != '\0')
			len2++;
	}
	if (n >= len2)
		n = len2;
	result = (char *) malloc((total_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		result[i] = s1[i];
	for (j = 0; j < n; j++)
		result[i++] = s2[j];
	result[i] = '\0';
	return (result);
}
