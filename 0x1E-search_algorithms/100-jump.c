#include "search_algos.h"
#include <math.h>

/**
 * jump_search - Perform jump search on a sorted array.
 *
 * This function implements jump search, a searching
 * algorithm for sorted arrays.
 * It uses a jumping step to quickly navigate through
 * the array to find the index
 * where the specified value is located.
 *
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where the value is located, or -1 if not found.
 */
int jump_search(int *array, size_t size, int value)
{
size_t jmp, st, lim;

if (!array || size == 0)
return (-1);
jmp = (size_t) sqrt(size);
st = lim = 0;
while ((lim < size) && (array[lim] < value))
{
printf("Value checked array[%lu] = [%d]\n", lim, array[lim]);
st = lim;
lim += jmp;
}
printf("Value found between indexes [%lu] and [%lu]\n", st, lim);
lim = lim < size - 1 ? lim : size - 1;
while ((array[st] < value) && (st < lim))
{
printf("Value checked array[%lu] = [%d]\n", st, array[st]);
st++;
}
printf("Value checked array[%lu] = [%d]\n", st, array[st]);
return (array[st] == value ? (int) st : -1);
}
