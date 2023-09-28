#include "main.h"

/**
 * get_bit - returns the value of a bit
 * @n: unsigned long int input
 * @index: index of the bit
 * Return: value
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int value;

	if (index > 63)
		return (-1);
	value = (n >> index) & 1;

	return (value);
}
