#include "variadic_functions.h"

/**
 * print_strings - prints strings followed by a newline
 * @separator: string to be printed between the strings
 * @n: number of strings to be passed
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	char *str;
	unsigned int i;

	va_start(args, n);

	if (separator == NULL)
		separator = "";

	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);

		if (str == NULL)
			str = "(nil)";
		else
			printf("%s", str);

		if (i < n - 1)
			printf("%s", separator);
	}
	printf("\n");
	va_end(args);
}
