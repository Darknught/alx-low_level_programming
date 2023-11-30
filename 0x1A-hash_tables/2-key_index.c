#include "hash_tables.h"

/**
 * key_index - gets the index of a key in the hash table array
 * @ley: the key to be hashed
 * @size: size of the array (hast table)
 *
 * Return: The index at which the key should be stored in the array
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
