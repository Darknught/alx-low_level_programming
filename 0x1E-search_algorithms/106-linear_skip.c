#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of int
 * @list: A pointer to the head of the skip list
 * @value: Value to search for
 * Return: Pointer to the first node where val is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev, *node;

	if (list == NULL)
		return (NULL);

	prev = list;
	node = list->express;

	while (node && node->n < value)
	{
		prev = node;
		node = node->express;

		if (node)
			printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, node ? node->index : prev->index);

	while (prev && prev->index <= (node ? node->index : prev->index))
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);

		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}
