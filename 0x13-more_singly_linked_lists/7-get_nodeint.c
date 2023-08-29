#include "lists.h"

/**
 * get_nodeint_at_index - the nth node of a Listint_t list
 * @head: pointer to the first node
 * @index: index of the node
 * Return: pointer of index
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int x;

	if (head == NULL)
		return (NULL);
	for (x = 0; x < index; x++)
	{
		head = head->next;
		if (head == NULL)
			return (NULL);
	}
	return (head);
}
