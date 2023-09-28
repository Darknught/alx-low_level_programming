#include "main.h"

/**
 * binary_to_uint - function thats converts a binary number to unsigned int
 * @b: pointer to a binary string of 0 and 1 chars
 * Return: converted number or 0
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int val = 0;
	int i;

	if (!b)
		return (0);
	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
	}

	for (i = 0; b[i] != '\0'; i++)
	{
		val <<= 1;
		if (b[i] == '1')
			val += 1;
	}
	return (val);
}
