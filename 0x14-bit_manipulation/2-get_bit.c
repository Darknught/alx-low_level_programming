#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: checking bits
 * @index: which to check
 * Return: value of bit at index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int brig, gen;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	brig = 1 << index;
	gen = n & brig;

	if (gen == brig)
		return (1);

	return (0);
}
