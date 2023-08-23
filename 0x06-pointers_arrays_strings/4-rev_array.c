#include "main.h"

/**
 *  reverse_array -  reverses the content of an array of integers
 * @n:  number of elements of the array
 * @a:Pointer to the beginning of the integer array
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{

	int i;
	int j = n - 1;
	int tmp;

	for (i = 0; i < j; i++)
	{
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
		j--;
	}
}
