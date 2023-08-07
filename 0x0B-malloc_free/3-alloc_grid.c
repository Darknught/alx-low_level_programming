#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - returns a pointer to a two dimensional array of int
 * @width: int
 * @height: int
 * Return: pointer
 */
int **alloc_grid(int width, int height)
{
	int **array;
	int i;

	array = malloc(height * sizeof(int *));

	for (i = 0; i < height; i++)
	{
		array[i] = malloc(width * sizeof(int));
	}
	if (width == 0 || height == 0)
		return (NULL);

	return (array);
}

