#include "main.h"

/**
 * _strchr - locates a character in the string
 * @c: first character
 * @s: string
 * Return: s or Null
 */
char *_strchr(char *s, char c)
{

	while(*s)
	{
		if (*s != c)
			s++;
		else
			return(s);

	}
	if (c != '\0')
		return (s);

	return (0);
}
