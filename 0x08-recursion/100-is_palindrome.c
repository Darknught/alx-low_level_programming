#include "main.h"
/**
 * _strlen_recursion - prints length
 * @s: dtring
 * Return: length
 */
int _strlen_recursion(char *s)
{
	if (s[0] != '\0')
		return (1 + _strlen_recursion(s + 1));
	return (0);
}

/**
 * pal_check - check palindrome
 * @s: string
 * @y: left index
 * @z: right index
 * Return: 1, or 0 otherwise
 */
int pal_check(char *s, int y, int z)
{
	if (s[y] == s[z])
		if (y > z / 2)
			return (1);
		else
			return (pal_check(s, y + 1, z - 1));
	else
		return (0);
}

/**
 * is_palindrome - check if s is palindrome
 * @s: string
 * Return: 1, or 0 otherwise
 */
int is_palindrome(char *s)
{
	return (pal_check(s, 0, _strlen_recursion(s) - 1));
}
