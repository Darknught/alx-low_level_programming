#include "variadic_functions.h"

/**
 * print_numbers - prints numbers followed by a newline
 * @separator: string to be printed between numbers
 * @n: number of integers passed
 * Return: void
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	int number;
	unsigned int i;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		number = va_arg(args, int);
		printf("%d", number);

		if (i < n - 1 && separator != NULL)
			printf("%s", separator);
	}
	printf("\n");

	va_end(args);
}
