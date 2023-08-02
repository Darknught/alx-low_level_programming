#include "main.h"
/**
 * _puts_recursion - prints a string
 * @s: char to print
 * Return: void
 */
void _puts_recursion(char *s)
{

	if (*(s + 1))
	{
		_putchar(*s);
	}
	else
	{
		_putchar('\n');
	}
}
