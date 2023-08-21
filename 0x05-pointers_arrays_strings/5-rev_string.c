#include "main.h"

/**
 * rev_string -  reverses a string
 * @s: The stringh to be reversed
 *
 * Return: void
*/

void rev_string(char *s)
{
	int l = 0;
	int i;
	int j;
	char tmp;

	while (s[l] != '\0')
	{
		l++;
	}
	i = 0;
	j = l - 1;

	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}
