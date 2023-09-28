#include "main.h"

/**
 * clear_bit - sets the value of bit to 0 at a given index
 * @n: pointer to the number
 * @index: index of the bit
 *
 * Return: 1 if successful, -1 if failed
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
