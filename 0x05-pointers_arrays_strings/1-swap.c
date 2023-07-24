#include "main.h"
/**
 * swap_int - swap the values of two integers
 * @a: first integer
 * @b: second integer
 * Return: 0 (success)
 */
void swap_int(int *a, int *b)
{
	int s;

	s = *a;
	*a = *b;
	*b = s;
}
