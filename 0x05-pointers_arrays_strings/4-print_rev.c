#include "main.h"
/**
 * print_rev - prints string in reverse
 * @s: character to check
 * Return: 0 (success)
 */
void print_rev(char *s)
{
	int i, n;

	n = 0;
	while (s[n] != '\0')
		n++;

	for (i = n - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}
