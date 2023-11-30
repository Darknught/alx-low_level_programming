#include "hash_tables.h"

/**
 * hash_table_set - Adds or updates a key-value pair in the hash table
 * @ht: the hash table
 * @key: the key
 * @value: The value associated with the key
 *
 * Return: 1 if it succeeds, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *current, *new;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
	{
		return (0);
	}

	index = key_index((const unsigned char *)key, ht->size);
	new = NULL;

	current = ht->array[index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);

			if (current->value == NULL)
			{
				return (0);
			}
			return (1);
		}
		current = current->next;
	}

	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
	{
		return (0);
	}
	new->key = strdup(key);
	new->value = strdup(value);

	if (new->key == NULL || new->value == NULL)
	{
		free(new->key);
		free(new->value);
		free(new);
		return (0);
	}
	new->next = ht->array[index];
	ht->array[index] = new;

	return (1);
}
