#include "hash_tables.h"

/**
 * hash_table_free - Frees a hash table and its elements
 * @ht: hash table to free
 *
 */
void hash_table_free(hash_table_t *ht)
{
	hash_node_t *current, *next;
	unsigned long int i;

	if (ht == NULL)
	{
		return;
	}

	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		next;

		while (current != NULL)
		{
			next = current->next;
			free(current->key);
			free(current->value);
			free(current);
			current - next;
		}
	}
	free(ht->array);
	free(ht);
}
