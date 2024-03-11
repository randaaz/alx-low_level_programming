#include "search_algos.h"

/**
 * recursive_search - Recursively search for a value in a sorted array.
 *
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where the value is located, or -1 if not found.
 */
int recursive_search(int *array, size_t size, int value)
{
size_t hf = size / 2;
size_t j;

if (array == NULL || size == 0)
return (-1);

printf("Searching in array");

for (j = 0; j < size; j++)
printf("%s %d", (j == 0) ? ":" : ",", array[j]);

printf("\n");

if (hf && size % 2 == 0)
hf--;

if (value == array[hf])
return ((int)hf);

if (value < array[hf])
return (recursive_search(array, hf, value));

hf++;

return (recursive_search(array + hf, size - hf, value) + hf);
}

/**
 * binary_search - Perform binary search on a sorted array.
 *
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where the value is located, or -1 if not found.
 */
int binary_search(int *array, size_t size, int value)
{
int idx;

idx = recursive_search(array, size, value);

if (idx >= 0 && array[idx] != value)
return (-1);

return (idx);
}
