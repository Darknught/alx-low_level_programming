#include "main.h"
/**
 * check - check to see if a number is prime
 * @y: int
 * @z: int
 * Return: int
 */
int check(int y, int z)
{
	if (z < 2 || z % y == 0)
		return (0);
	else if (y > z / 2)
		return (1);
	else
		return (check(y + 1, z));
}

/**
 * is_prime_number - check for prime number
 * @n: int to check
 * Return: int
 */
int is_prime_number(int n)
{

	if (n == 2)
		return (1);
	return (check(2, n));
}
