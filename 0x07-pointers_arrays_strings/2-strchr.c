#include "main.h"
/**
 * _strchr - locates a character in the string
 * @c: first character
 * @s: string
 * Return: s or Null
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; i != c; i++)
	{
		if (c == '\0')
			return (s);
	}
	return (s);
}
