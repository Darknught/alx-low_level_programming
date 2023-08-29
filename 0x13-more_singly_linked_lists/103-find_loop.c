#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the start
 * Return: address of the node where the loop starts or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *begin, *gone;

	begin = gone = head;

	while (begin && gone && gone->next)
	{
		begin  = begin->next;
		gone = gone->next->next;

		if (begin == gone)
		{
			begin = head;
			break;
		}
	}
	if (!begin || !gone || !gone->next)
		return (NULL);
	while (begin != gone)
	{
		begin = begin->next;
		gone = gone->next;
	}
	return (gone);
}
