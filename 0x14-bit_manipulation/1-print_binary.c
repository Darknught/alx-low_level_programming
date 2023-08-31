#include "main.h"

/**
 * cal_power - calculates the power
 * @base: the base of the exponent
 * @exp: power of exponent
 * return: value of base and power
 */
unsigned long int cal_power(unsigned int base, unsigned int exp)
{
	unsigned long int result = 1;
	unsigned int x;

	for (x = 1; x <= exp; x++)
		result *= base;
	return (result);
}

/**
 * print_binary - outputs the binary representation of a number
 * @n: integer to print
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int result, size;
	char flags = 0;

	size = cal_power(2, sizeof(unsigned long int) * 8 - 1);

	while (size != 0)
	{
		result = n & size;
		if (result == size)
		{
			flags = 1;
			_putchar('1');
		}
		else if (flags == 1 || size == 1)
		{
			_putchar('0');
		}
		size >>= 1;
	}
}
