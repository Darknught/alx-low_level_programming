#include "variadic_functions.h"

/**
 * print_all - prints all the arguments
 * @format: specifies operations
 * Return: void
 */
void print_all(const char * const format, ...)
{
	char *s;
	int i;
	int fg;
	va_list tot_list;

	va_start(tot_list, format);

	for (i = 0; format != NULL && format[i] != '\0'; i++)
	{
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(tot_list, int));
				fg = 0;
				break;
			case 'i':
				printf("%d", va_arg(tot_list, int));
				fg = 0;
				break;
			case 'f':
				printf("%f", va_arg(tot_list, double));
				fg = 0;
				break;
			case 's':
				s = va_arg(tot_list, char*);
				if (s == NULL)
					s = "(nil)";
				printf("%s", s);
				fg = 0;
				break;
			default:
				fg = 1;
				break;
		}
		if (format[i + 1] != '\0' && fg == 0)
			printf(", ");
	}
	printf("\n");
	va_end(tot_list);
}
