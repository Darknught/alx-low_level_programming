#include "search_algos.h"

/**
 * exponential_search - Searches for a value in a sorted array of int
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in an array
 * @value: The value to earch for
 * Return: The first index where is located, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i, start, end;
	int res;

	if (array == NULL || size == 0)
		return (-1);

	i = 1;
	while (i < size && array[i] <= value)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		i *= 2;
	}
	start = i / 2;
	end = (i < size - 1) ? i : size - 1;

	printf("Value found between indexes [%lu] and [%lu]\n", start, end);

	res = binary_search(array + start, end - start + 1, value);
	if (res == -1)
		return (-1);
	return (res + start);
}
