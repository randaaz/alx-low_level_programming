#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of chars,
 * and initializes it with a specific char
 * @size: the size of array
 * @c: the charachter
 * Return: ointer to the array, or NULL if it fails
 */

char *create_array(unsigned int size, char c)
{

	if (size == 0)
	{
		return (NULL);
	}
	char *ptr;

	ptr = (char *) malloc(sizeof(char) * size);

	if (ptr == NULL)
	{
		return (NULL);
	}
	else
	{
		int i;

		for (i = 0; i < size; i++)
		{
			ptr[i] = c;
		}
	}
	return (ptr);
}
