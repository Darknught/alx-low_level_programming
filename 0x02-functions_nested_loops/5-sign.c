#include "main.h"
/**
 * print_sign - prints sign of a number
 * @n: number whcih will be printed
 * Return: 1 if number is greater than zero, 0 if it is zero, otherwise -1
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	else
	{
		_putchar('-');
		return (-1);
	}
}
