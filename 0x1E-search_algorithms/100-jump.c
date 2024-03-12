#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of int
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in the array
 * @value: The value to search for
 * Return: The first index where value is located, or -1 if value is NULL
 */
int jump_search(int *array, size_t size, int value)
{
	int left = 0, ryt = 0, i;
	int jump = sqrt(size);

	if (array == NULL)
		return (-1);

	while (ryt < (int)size && array[ryt] < value)
	{
		printf("Value checked array[%d] = [%d]\n", ryt, array[ryt]);
		left = ryt;
		ryt += jump;
	}
	printf("Value found between indexes [%d] and [%d]\n", left, ryt);

	for (i = left; i <= ryt && i < (int)size; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
