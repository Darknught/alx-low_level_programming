#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * str_concat - concatinates two strings
 * @s1: destination string
 * @s2: source string
 * Return: NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *ptr;
	int i, j, len1, len2, len;

	len1 = len2 = 0;

	if (s1 != NULL)
	{
		i = 0;
		while (s1[i++] != '\0')
			len1++;
	}
	if (s2 != NULL)
	{
		i = 0;
		while (s2[i++] != '\0')
			len2++;
	}
	len = len1 + len2;

	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		ptr[i] = s1[i];
	for (j = 0; j < len2; j++, i++)
		ptr[i] = s2[j];
	ptr[len] = '\0';
	return (ptr);
}
