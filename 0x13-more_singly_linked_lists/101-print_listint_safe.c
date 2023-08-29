#include "lists.h"

/**
 * rm - reallocates memory for array of pointers
 * @list: the old list
 * @size: size of the new list
 * @new: new node
 * Return: pointer to the new list
 */
const listint_t **rm(const listint_t **list, size_t size, const listint_t *new)
{
	const listint_t **newl;
	size_t x;

	newl = malloc(size * sizeof(listint_t *));

	if (newl == NULL)
	{
		free(list);
		exit(98);
	}
	for (x = 0; x < size - 1; x++)
		newl[x] = list[x];
	newl[x] = new;
	free(list);
	return (newl);
}

/**
 * print_listint_safe - prints a listint_t list
 * @head: pointer to the start of list
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t x, number = 0;
	const listint_t **list = NULL;

	while (head != NULL)
	{
		for (x = 0; x < number; x++)
		{
			if (head == list[x])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(list);
				return (number);
			}
		}
		number++;
		list = rm(list, number, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(list);
	return (number);
}
