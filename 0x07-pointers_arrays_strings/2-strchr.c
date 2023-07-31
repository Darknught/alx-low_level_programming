#include "main.h"
/**
 * _strchr - locates a character in the string
 * @c: first character
 * @s: string
 * Return: s or Null
 */
char *_strchr(char *s, char c)
{
	while (*s != c && *s != '\0')
		s++;

	if (*s == c)
		return (s);
	return (0);
}
