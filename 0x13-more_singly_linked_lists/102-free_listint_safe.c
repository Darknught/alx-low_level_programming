#include "lists.h"
/**
 * rp - reallocates memory for an array of pointers
 * @list: the old list to append
 * @size: size of the new list (more than the old)
 * @new: new node to add
 * Return: pointer to the new list
 */
listint_t **rp(listint_t **list, size_t size, listint_t *new)
{
	listint_t **freshlist;
	size_t j;

	freshlist = malloc(size * sizeof(listint_t *));
	if (freshlist == NULL)
	{
		free(list);
		exit(98);
	}
	for (j = 0; j < size - 1; j++)
		freshlist[j] = list[j];
	freshlist[j] = new;
	free(list);
	return (freshlist);
}

/**
 * free_listint_safe - frees a listint_t list
 * @head: double pointer to the start
 * Return: number of nodes in the list
 */
size_t free_listint_safe(listint_t **head)
{
	size_t m, number = 0;
	listint_t **list = NULL;
	listint_t *next;

	if (head == NULL || *head == NULL)
		return (number);
	while (*head != NULL)
	{
		for (m = 0; m < number; m++)
		{
			if (*head == list[m])
			{
				*head = NULL;
				free(list);
				return (number);
			}
		}
		number++;
		list = rp(list, number, *head);
		next = (*head)->next;
		free(*head);
		*head = next;
	}
	free(list);
	return (number);
}
