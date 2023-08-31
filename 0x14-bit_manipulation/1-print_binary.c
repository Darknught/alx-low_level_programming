#include "main.h"

/**
 * print_binary - outputs the binary representation of a number
 * @n: integer to print
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned int size = sizeof(unsigned long int) * 8;
	unsigned int i;

	for (i = 1UL << (size - 1); i > 0; i = i >> 1)
	{
		if (n & i)
		{
			_putchar('1');
		}
		else
		{
			_putchar('0');
		}
	}
}
