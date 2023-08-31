#include "main.h"

/**
 * clear_bit - set a value of bit to 0 at a given index
 * @n: number of x
 * @index: starting from 0
 * Return: 1 if it worked, or -1 if it fails
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int x;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	x = ~(1 << index);
	*n = *n & x;

	return (1);
}
