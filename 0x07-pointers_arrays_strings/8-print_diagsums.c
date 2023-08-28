#include <stdio.h>
#include "main.h"

/**
 *  print_diagsums - prints the sum of the two
 * diagonals of a square matrix of integers
 * @a: pointer to a int
 * @size: size of array
 *
 * Return: pointer
 */
void print_diagsums(int *a, int size)
{
	int i, sum = 0, sum1 = 0;

	for (i = 0; i < size; i++)
	{
		sum += a[i * size + i];
		sum1 += a[i * size + (size - 1 - i)];
	}

	printf("%d, ", sum);
	printf("%d\n", sum1);
}
