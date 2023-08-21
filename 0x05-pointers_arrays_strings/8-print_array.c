#include "main.h"

/**
 *  print_array - that prints n elements of an array
 *  of integers, followed by a new line
 *  @a: the array of integers
 *  @n: the number of elements to print
 *
 *  Return: void
*/

void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if (i != n - 1)
		{
			printf(", ");
		}
	}
	printf("\n");
}
