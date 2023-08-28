#include "main.h"

/**
 * _strchr - locates a character in a string
 * @s:  pointer to a string
 * @c: the character
 *
 * Return: pointer
*/

char *_strchr(char *s, char c)
{
	if (s == NULL)
	{
		return (NULL);
	}
	while (*s >= '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}
