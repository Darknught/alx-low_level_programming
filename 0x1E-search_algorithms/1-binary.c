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
