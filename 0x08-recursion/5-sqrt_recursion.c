#include "main.h"
/**
 * check - checks for squares
 * @y: int
 * @z: int
 * Return: int
 */
int check(int y, int z)
{
	if (y * y == z)
		return (y);
	if (y * y > z)
		return (-1);
	return (check(y + 1, z));
}
/**
 * _sqrt_recursion - returns natural square root
 * @n: int
 * Return: int
 */
int _sqrt_recursion(int n)
{
	if (n == 0)
		return (0);
	return (check(1, n));
}
