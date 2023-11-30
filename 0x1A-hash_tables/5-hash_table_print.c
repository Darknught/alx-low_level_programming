#include "hash_tables.h"

/**
 * hash_table_print - Prints the key-value pairs of a hash table
 * @ht: The hash table to print
 *
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *current;
	unsigned long int i;
	char myflag = 0; /*while no data has been printed yet */

	if (ht == NULL)
	{
		return;
	}

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];

		while (current != NULL)
		{
			if (myflag == 1)
				printf(", ");
			printf("'%s': '%s'", current->key, current->value);
			myflag = 1;
			current = current->next;
		}
	}
	printf("}\n");
}
