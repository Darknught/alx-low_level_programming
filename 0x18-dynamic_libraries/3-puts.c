#include "main.h"
/**
 * _puts - prints string followed by a new line
 * @str: the string
 * Return: len of the string
 */
void _puts(char *str)
{
	int j = 0;

	while (str[j] != '\0')
	{
		_putchar(str[j]);
		j++;
	}
	_putchar('\n');
}
