#include <stdio.h>
/**
 * main - prints the lowercase alphabets in reverse folloewd by a new line
 *
 * Return: 0 (success)
 */
int main(void)
{
	char letter;

	for (letter = 'z'; letter >= 'a'; letter--)
		putchar(letter);

	putchar('\n');
	return (0);
}
