#include "lists.h"

/**
 * free_list - Releases the memory allocated for the list
 * @head: pointer to the first node
 */
void free_list(list_t *head)
{
	if (head)
	{
		free_list(head->next);

		if (head->str)
			free(head->str);
		free(head);
	}
}
