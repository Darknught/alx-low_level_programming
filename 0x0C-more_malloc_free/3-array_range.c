#include "main.h"
#include <stdlib.h>
/**
 * array_range - creates an array of int
 * @min: minimun int range
 * @max: maximun int range
 * Return: pointer to the newly created array
 */
int *array_range(int min, int max)
{
	int *s;
	int i = 0;
	int size;

	if (min > max)
		return (NULL);
	size = max - min + 1;

	s = malloc(sizeof(int) * size);

	if (s == NULL)
		return (NULL);

	while (min <= max)
	{
		s[i] = min++;
		i++;
	}
	return (s);
}
