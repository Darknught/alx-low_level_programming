#include "lists.h"

/**
 * listint_len - returns number of elements in a linked listint_t list
 * @h: head pointer
 * Return: number of elements
 */
size_t listint_len(const listint_t *h)
{
	size_t counting = 0;

	while (h != NULL)
	{
		h = h->next;
		counting++;
	}
	return (counting);
}
