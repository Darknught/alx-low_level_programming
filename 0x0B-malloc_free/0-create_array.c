#include "main.h"
#include <stdlib.h>
/**
 * create_array - creates an array of chars, and initializes
 * @size: size of type
 * @c: char
 * Return: NULL is size is 0
 */
char *create_array(unsigned int size, char c)
{
	char *number;
	unsigned int i = 0;

	number = (char *)malloc(sizeof(char) * size);

	if (size == 0)
	{
		return (NULL);
	}
	if (number == NULL)
	{
		return (NULL);
	}
	while (i < size)
	{
		number[i] = c;
		i++;
	}
	return (number);
}
