#include "main.h"
#include <stdlib.h>
/**
 * _strdup - Returns a pointer to a newly allocated space
 * @str: original string
 * Return: NULL if str is null or no memory
 */
char *_strdup(char *str)
{
	char *dstr;
	int i = 0, len = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[len] != '\0')
		len++;

	dstr =(char *)malloc((sizeof(char) * len) + 1);
	if (dstr == NULL)
	{
		return (NULL);
	}
	while (i < len)
	{
		dstr[i] = str[i];
		i++;
	}
	dstr[len] = '\0';

	return (dstr);
}
