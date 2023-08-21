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
	unsigned int res = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign *= -1;
			i++;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			res = res * 10 + (s[i] - '0');
		}
		else if (s[i] == '+')
		{
			i++;
		}
		else if (res > 0)
		{
			break;
		}
		i++;
	}
	return (res * sign);
}
