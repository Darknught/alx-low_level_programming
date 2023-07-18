#include <stdio.h>
#include "main.h"
/**
 * main - prints alphabets in lowercase
 *
 * Return: 0 (success)
 */
int main(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
		_putchar(letter);
	_putchar('\n');
	return (0);
}
