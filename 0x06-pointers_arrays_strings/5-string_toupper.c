#include "main.h"

/**
 * string_toupper - changes all lowercase letters of a string to uppercase
 * @upper: the string we want to cahnge
 *
 * Return: string whith uppercase
 */

char *string_toupper(char *upper)
{
	int i;

	for (i = 0; upper[i] != '\0'; i++)
	{
		if (upper[i] >= 'a' && upper[i] <= 'z')
		{
			upper[i] = upper[i] - 32;
		}
	}

	return (upper);
}
