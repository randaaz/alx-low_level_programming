#include "search_algos.h"

/**
 * rec_search - Recursive search within a sorted array.
 *
 * This function performs recursive search within a sorted array, printing the
 * array being searched during the process.
 *
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where the value is located, or -1 if not found.
 */
int rec_search(int *array, size_t size, int value)
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
{
if (hf > 0)
return (rec_search(array, hf + 1, value));
return ((int)hf);
}

if (value < array[hf])
return (rec_search(array, hf + 1, value));

hf++;
return (rec_search(array + hf, size - hf, value) + hf);
}

/**
 * advanced_binary - Perform advanced binary search on a sorted array.
 *
 * This function uses a recursive search approach to find the index of the
 * specified value in the sorted array. It handles the case where the value is
 * not present at the found index.
 *
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where the value is located, or -1 if not found.
 */
int advanced_binary(int *array, size_t size, int value)
{
int idx;

idx = rec_search(array, size, value);

if (idx >= 0 && array[idx] != value)
return (-1);

return (idx);
}
