#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: the string we want to  convert
 *
 * Return: The converted integer
*/

int _atoi(char *s)
{
	unsigned int res = 0;
	int sign = 1;
	int i = 0;

	while (*s != '\0')
	{
		if (*s == '-')
		{
			sign *= -1;
			i++;
		}
		else if (*s >= '0' && *s <= '9')
		{
			res = res * 10 + (*s - '0');
		}
		else if (i)
		{
			break;
		}
		s++;
	}
	return (res * sign);
}
