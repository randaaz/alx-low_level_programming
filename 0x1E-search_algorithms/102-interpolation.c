#include "search_algos.h"

/**
 * interpolation_search - Perform interpolation search on a sorted array.
 *
 * This function uses interpolation search to find the index of the specified
 * value in the sorted array. It prints the checked values during the search
 * process.
 *
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where the value is located, or -1 if not found.
 */
int interpolation_search(int *array, size_t size, int value)
{
size_t po, l, hi;
double fe;

if (array == NULL)
return (-1);

l = 0;
hi = size - 1;

while (size)
{
fe = (double)(hi - l) / (array[hi] - array[l]) * (value - array[l]);
po = (size_t)(l + fe);
printf("Value checked array[%d]", (int)po);

if (po >= size)
{
printf(" is out of range\n");
break;
}
else
{
printf(" = [%d]\n", array[po]);
}

if (array[po] == value)
return ((int)po);

if (array[po] < value)
l = po + 1;
else
hi = po - 1;

if (l == hi)
break;
}

return (-1);
}
