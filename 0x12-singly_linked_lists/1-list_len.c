#include "lists.h"

/**
 * list_len - returns the number of elements
 * @h: name of the list
 * Return: number of nodes
 */
size_t list_len(const list_t *h)
{
	int check = 0;

	while (h)
	{
		check++;
		h = h->next;
	}
	return (check);
}
