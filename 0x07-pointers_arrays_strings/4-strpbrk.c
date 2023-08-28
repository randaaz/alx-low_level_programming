#include "main.h"

/**
 * *_strpbrk - searches a string for any of a set of bytes
 * @s: pointer to a string
 * @accept: pointer to a string
 *
 * Return: pointer
 */
char *_strpbrk(char *s, char *accept)
{
	unsigned int i;
	unsigned int j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				return (&s[i]);
			}
		}
	}
	return (NULL);
}
