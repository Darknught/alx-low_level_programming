#include "function_pointers.h"
/**
 * array_iterator - executes function given as a parameter on each element
 * @array: array to execute
 * @size: the size of array
 * @action: pointer to the function to use
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t x;

	if (array && action)
	{
		for (x = 0; x < size; x++)
		{
			action(array[x]);
		}
	}
}
