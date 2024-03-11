#include "search_algos.h"

/**
 * _binary_search - Perform binary search on a sorted array within a range.
 *
 * This helper function performs binary search on a sorted array within the
 * specified range. It prints the array being searched during the process.
 *
 * @array: Pointer to the first element of the array to search in.
 * @left: The starting index of the search range.
 * @right: The ending index of the search range.
 * @value: The value to search for.
 *
 * Return: The index where the value is located, or -1 if not found.
  */
int _binary_search(int *array, size_t left, size_t right, int value)
{
size_t j;

if (array == NULL)
return (-1);

while (right >= left)
{
printf("Searching in array: ");
for (j = left; j < right; j++)
printf("%d, ", array[j]);
printf("%d\n", array[j]);

j = left + (right - left) / 2;
if (array[j] == value)
return (j);
if (array[j] > value)
right = j - 1;
else
left = j + 1;
}

return (-1);
}

/**
 * exponential_search - Perform exponential search on a sorted array.
 *
 * This function uses exponential search to find the index of the specified
 * value in the sorted array. It prints the checked values during the search
 * process.
 *
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where the value is located, or -1 if not found.
 */
int exponential_search(int *array, size_t size, int value)
{
size_t j = 0, right;

if (array == NULL)
return (-1);

if (array[0] != value)
{
for (j = 1; j < size && array[j] <= value; j = j * 2)
printf("Value checked array[%ld] = [%d]\n", j, array[j]);
}

right = j < size ? j : size - 1;
printf("Value found between indexes [%ld] and [%ld]\n", j / 2, right);
return (_binary_search(array, j / 2, right, value));
}
