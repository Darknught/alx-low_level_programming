#include "lists.h"

/**
 * free_dlistint - frees the list
 * @head: pointer to the beginning of the list
 *
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *checknode, *nextN;

	checknode = head;

	while (checknode != NULL)
	{
		nextN = checknode->next;
		free(checknode);
		checknode = nextN;
	}
}
