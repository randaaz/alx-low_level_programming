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

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int l1 = 0;
	int l2 = 0;
	int cy = 0;
	int sum, i, j, c;
	char tmp;

	while (n1[l1] != '\0')
	{
		l1++;
	}
	while (n2[l2] != '\0')
	{
		l2++;
	}
	if (l1 >  size_r - 1 || l2 > size_r - 1)
	{
		return (0);
	}
	i = l1 - 1;
	j = l2 - 1;
	c = 0;

	while (i >= 0 || j >= 0 || cy)
	{
		sum = cy;
		if (i >= 0)
		{
			sum += n1[i] - '0';
		}
		if (j >= 0)
		{
			sum += n2[j] - '0';
		}
		cy = sum / 10;
		r[c] = sum % 10 + '0';
		i--;
		j--;
		c++;
	}
	if (c >= size_r)
	{
		return (0);
	}
	r[c] = '\0';
	for (i = 0, j = c - 1; i < j; i++, j--)
	{
		tmp = r[i];
		r[i] = r[j];
		r[j] = tmp;
	}
	return (r);
}
