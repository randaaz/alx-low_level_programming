#include "function_pointers.h"

/**
 * int_index - Searches for an integer in an array.
 * @array: Pointer to an array of integers.
 * @size: The size of the array.
 * @cmp: Pointer to the comparison function.
 *
 * Return: Index of the first matching element, or -1 if no match is found.
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i, res;

	if (array == NULL || cmp == NULL || size <= 0)
	{
		return (-1);
	}
	for (i = 0; i < size; i++)
	{

		res = (*cmp) (array[i]);
		if (res != 0)
		{
			return (i);
		}
	}
	return (-1);
}
