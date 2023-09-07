#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: the first number
 * @max: the last number
 * Return: the pointer to the newly created array
 * or NULL if If min > max or malloc fails
 */

int *array_range(int min, int max)
{
	int *ptr;
	unsigned int i;

	ptr = malloc(sizeof(int) * (max - min) + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	if (min > max)
	{
		return (NULL);
	}
	for (i = 0; min <= max; i++)
	{
		ptr[i] = min;
		min++;
	}
	return (ptr);
}
