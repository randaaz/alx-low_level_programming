#include "main.h"

/**
 * swap_int - swaps the values of two integers
 * @a: The frist integer
 * @b: The secound number integer
*/
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
