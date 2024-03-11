#include "search_algos.h"

/**
 * linear_search - Search for a value in an array using linear search.
 *
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first index where the value is located, or -1 if not found.
 */
int linear_search(int *array, size_t size, int value)
{
int j;

if (array == NULL)
return (-1);

for (j = 0; j < (int)size; j++)
{
printf("Value checked array[%u] = [%d]\n", j, array[j]);
if (value == array[j])
return (j);
}
return (-1);
}
