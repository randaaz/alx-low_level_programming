#include "main.h"

/**
 * infinite_add -  adds two numbers
 * @n1: the first numbers
 * @n2: the second numbers
 * @r: the buffer that the function will use to store the result
 * @size_r:  the buffer size
 *
 * Return: The result of adding two numbers
 */

#include "main.h"

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int l1 = 0, l2 = 0, cy = 0, sum, i, j, c = 0;
	char tmp;

	while (n1[l1])
		l1++;
	while (n2[l2])
		l2++;

	if (l1 > size_r - 1 || l2 > size_r - 1)
		return (NULL);

	i = l1 - 1;
	j = l2 - 1;

	while (i >= 0 || j >= 0 || cy)
	{
		sum = cy + (i >= 0 ? n1[i] - '0' : 0) + (j >= 0 ? n2[j] - '0' : 0);
		cy = sum / 10;
		r[c++] = sum % 10 + '0';
		i--;
		j--;
	}

	if (c >= size_r)
		return (NULL);

	r[c] = '\0';

	for (i = 0, j = c - 1; i < j; i++, j--)
	{
		tmp = r[i];
		r[i] = r[j];
		r[j] = tmp;
	}

	return (r);
}
