#include "function_pointers.h"

/**
 * array_iterator - Apply a function to each element of an array.
 * @array: Pointer to an array of integers.
 * @size: The size of the array.
 * @action: Pointer to the function to be applied to each element.
 *
 * Return: void
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		(*action) (array[i]);
	}
}
