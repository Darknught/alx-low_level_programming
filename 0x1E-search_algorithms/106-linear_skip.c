#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of int
 * @list: A pointer to the head of the skip list
 * @value: Value to search for
 * Return: Pointer to the first node where val is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev, *curr = list;

	if (list == NULL)
		return (NULL);

	while (curr && curr->n < value)
	{
		prev = curr;
		if (curr->express == NULL)
		{
			while (curr->next)
				curr = curr->next;
			break;
		}
		printf("Value checked at index [%lu] = [%d]\n",
				curr->express->index, curr->express->n);
		curr = curr->express;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
			prev ? prev->index : 0, curr->index);

	while (prev && prev->index < curr->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);

		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	if (prev && prev->index > curr->index)
		printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
	printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
	return (NULL);
}
