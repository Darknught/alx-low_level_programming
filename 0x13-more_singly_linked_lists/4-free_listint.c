#include "lists.h"

/**
 * free_listint - frees a linstint_t list
 * @head: head of the list
 * Return: NULL if theres error
 */
void free_listint(listint_t *head)
{
	listint_t *next;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
