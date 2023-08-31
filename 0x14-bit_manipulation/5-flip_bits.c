#include "main.h"

/**
 * flip_bits - flip to get from one number to the other
 * @n: first number
 * @m: second number
 * Return: number of bits we need
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff, outcme;
	unsigned int i, j = 0;

	outcme = 1;
	diff = n ^ m;

	for (i = 0; i < (sizeof(unsigned long int) * 8); i++)
	{
		if (outcme == (diff & outcme))
			j++;
		outcme <<= 1;
	}
	return (j);
}
