#include "lists.h"
/**
 * _strlen - function to return the length of string
 * @s: character
 * Return: value
 */
int _strlen(const char *s)
{
	int x = 0;

	while (s[x] != '\0')
	{
		x++;
	}
	return (x);
}

/**
 * add_node - add node t the beginning of a list
 * @head: head of the list list_t
 * @str: value to the element inserted
 * Return: number of nodes
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *add;

	add = malloc(sizeof(list_t));

	if (add == NULL)
		return (NULL);
	add->str = strdup(str);

	add->len = _strlen(str);
	add->next = *head;
	*head = add;

	return (add);
}
