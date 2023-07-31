#include "main.h"
#include <stddef.h>
/**
 * _strchr - locates a character in the string
 * @c: first character
 * @s: string
 * Return: s or Null
 */
char *_strchr(char *s, char c)
{

	for (; *s != c; s++)
	{
		if (*s == '\0')
			return (s);
	}
	return (NULL);
}
