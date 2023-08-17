#include "variadic_functions.h"

/**
 * sum_them_all - returns yhe sum of all its parameters
 * @n: number of arguments
 * Return: sum, 0 if number of argument is NULL
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	int sum = 0;
	unsigned int i;
	int value;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		value = va_arg(args, int);
		sum += value;
	}
	va_end(args);
	return (sum);
}
