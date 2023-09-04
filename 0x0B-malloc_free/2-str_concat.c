#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: The first string
 * @s2: The second steing
 *
 * Return: Pointer to the concatenated string or NULL if it fails
 */

char *str_concat(char *s1, char *s2)
{
	unsigned int i, j;
	char *new;
	int l1 = 0;
	int l2 = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	if (s1 == NULL && s2 == NULL)
	{
		return (NULL);
	}
	for (i = 0; s1[i] != '\0'; i++)
	{
		l1++;
	}
	for (i = 0; s2[i] != '\0'; i++)
	{
		l2++;
	}
	new = (char *)malloc(sizeof(char) * (l1 + l2 + 1));

	if (new == NULL)
	{
		return (NULL);
	}
	else
	{
		for (i = 0; s1[i] != '\0'; i++)
		{
			new[i] = s1[i];
		}
		for (j = 0; s2[j] != '\0'; j++)
		{
			new[i + j] = s2[j];
		}
		new[i + j] = '\0';
	}
	return (new);
}
