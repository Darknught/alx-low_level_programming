#include "main.h"
/**
 * factorial - returns factorial of a given number
 * @n: number to return
 * Return: integer
 */
int factorial(int n)
{

	if (n <= 1)
	{
		if (n < 0)
		{
			return (-1);
		}
		return (1);
	}
	else
	{
		return (n * factorial(n - 1));
	}
	return (0);
}
