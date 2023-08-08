#include "main.h"
#include <stdlib.h>
/**
 * argstostr - concatenates all arguments
 * @ac: argument to count
 * @av: pointer to an argument
 * Return: NULL
 */
char *argstostr(int ac, char **av)
{
	int i, j, k;
	int len = 0;
	char *str, *p;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		p = av[i];
		j = 0;

		while (p[j++])
			len++;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);

	for (i = 0, j = 0; i < ac && j < len; i++)
	{
		p = av[i];
		k = 0;

		while (p[k])
		{
			str[j] = p[k];
			k++;
			j++;
		}
		str[j++] = '\n';
	}
	str[j] = '\0';
	return (str);
}
