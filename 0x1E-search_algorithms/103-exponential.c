#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array of integers
 * @array: A pointer to the first element of the array to search
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where is located, or -1 if val is not present pr if NULL
 */
int binary_search(int *array, size_t size, int value)
{
	int low = 0, high, mid;
	size_t i;

	if (array == NULL)
		return (-1);

	high = size - 1;

	while (low <= high)
	{
		mid = (low + high) / 2;
		printf("Searching in array: ");
		for (i = low; i <= (size_t)high; i++)
		{
			printf("%d", array[i]);
			if (i < (size_t)high)
				printf(", ");
			else
				printf("\n");
		}

		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}

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
