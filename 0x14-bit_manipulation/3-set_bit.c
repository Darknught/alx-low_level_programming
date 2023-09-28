#include "main.h"

/**
 * set_bit - sets the value of bit to 1
 * @n: number to set
 * @index: index at which to set
 * Return: 1 if worked, -1 if theres an error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);
	*n = ((1UL << index) | *n);
	return (1);
}
