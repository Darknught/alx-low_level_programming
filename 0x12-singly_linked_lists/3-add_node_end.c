#include "lists.h"
/**
 * _strlen - get the length of a string
 * @s: string
 * Return: length
 */
unsigned int _strlen(char *str)
{
	int i = 0;

	while (str[i])
	{
		i++;
	}
	return (i);
}

/**
 * add_node_end - adds a node at the end of the lists
 * @head: double pointer to the list
 * @str: string to add the pointer
 * Return: pointer to the new node
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *temp;

	if (str == NULL)
		return (NULL);
	new = malloc(sizeof(list_t));

	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	new->len = _strlen(new->str);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (new);
}
