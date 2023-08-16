#include "function_pointers.h"
/**
 * int_index - searches for an integer
 * @size: number of elements in array
 * @array: array to execute
 * @cmp: pointer to function
 * Return: index of the first element, or -1 if no element
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (size > 0)
	{
		if (array != NULL && cmp != NULL)
		{
			for (i = 0; i < size; i++)
			{
				if (cmp(array[i]))
					return (i);
			}
		}
	}
	return (-1);
}
