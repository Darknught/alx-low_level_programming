#include "lists.h"

/**
 * print_list - prints all the elements of a list
 * @h: name of the list
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	int check = 0;

	while (h)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%d] %s\n", h->len, h->str);
		}
		check++;

		h = h->next;
	}
	return (check);
}
