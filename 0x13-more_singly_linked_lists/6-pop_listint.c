#include "lists.h"

/**
 * pop_listint - deletes the head node
 * @head: head of a double pointer
 * Return: the head nodes data
 */
int pop_listint(listint_t **head)
{
	listint_t *beginning;
	int n;

	if (head == NULL || *head == NULL)
		return (0);
	beginning = *head;
	*head = beginning->next;
	n = beginning->n;
	free(beginning);
	return (n);
}
