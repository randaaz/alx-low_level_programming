#include "main.h"
#include <stdlib.h>

/**
 * _strdup -returns a pointer to a newly allocated space in memory
 * which contains a copy of the string given as a parameter.
 * @str: The string to duplicate
 *
 * Return: Pointer to the duplicated string or NULL if it fails
 */

char *_strdup(char *str)
{
	unsigned int i;
	char *new;
	int l = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		l++;
	}
	new = (char *) malloc(sizeof(char) * (l + 1);

	if (new == NULL)
	{
		return (NULL);
	}
	else
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			new[i] = str[i];
		}
		new[i] = '\0';
	}
	return (new);
}
