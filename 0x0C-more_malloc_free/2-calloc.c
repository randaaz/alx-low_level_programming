#include "main.h"
#include <stdlib.h>

/**
 * _calloc - creates an array of chars,
 * and initializes it with a specific char
 * @size: the size of array
 * @nmemb : the charachter
 * Return: ointer to the array, or NULL if it fails
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	ptr = malloc(sizeof(char) * (nmemb * size));
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < nmemb * size; i++)
	{
		ptr[i] = 0;
	}
	return (ptr);
}
