#include "main.h"
/**
 * _strlen_recursion - returns the length of a string
 * @s: string
 * Return: an integer
 */
int _strlen_recursion(char *s)
{
	if (*s)
	{
		return (0);
	}
	s++;
	_strlen_recursion(s + 1);

	return (0);
}
