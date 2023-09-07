#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: the first number
 * @max: the last number
 * Return: the pointer to the newly created array
 * or NULL if min > max or malloc fails
 */
int *array_range(int min, int max)
{
	int *ptr;
	int i, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;
	ptr = malloc(sizeof(int) * size);

	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		ptr[i] = min;
		min++;
	}

	return (ptr);
}

