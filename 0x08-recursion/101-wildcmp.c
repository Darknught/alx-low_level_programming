#include "main.h"
/**
 * str_check - check if two strings are identical
 * @s1: string 1
 * @s2: string 2
 * @i: int
 * @j: int
 * Return: 1 or 0 otherwise
 */
int str_check(char *s1, char *s2, int i, int j)
{
	if (s1[i] == '\0' && s2[j] == '\0')
		return (1);
	if (s1[i] == s2[j])
		return (str_check(s1, s2, i + 1, j + 1));
	if (s1[i] == '\0' && s2[j] == '*')
		return (str_check(s1, s2, i, j + 1));
	if (s2[j] == '*')
		return (str_check(s1, s2, i + 1, j) || str_check(s1, s2, i, j + 1));
	return (0);
}

/**
 * wildcmp - check if string is identical
 * @s1: string 1
 * @s2: string 2
 * Return: 1 if identical
 */
int wildcmp(char *s1, char *s2)
{
	return (str_check(s1, s2, 0, 0));
}
