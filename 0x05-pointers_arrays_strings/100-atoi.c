#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: the string we want to  convert
 *
 * Return: The converted integer
*/

int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int res = 0;

	if (s[i] == '-')
	{
		sign = -1;
	       i++;
	}
	else if (s[i] == '+')
	{
		i++;
	}
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			res = res * 10 + (s[i] - '0');
			i++;
		}
		else
		{
			break;
		}
	}
	return (res * sign);

}
