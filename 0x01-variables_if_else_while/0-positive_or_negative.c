#include <stdio.h>

#include <stdlib.h>
#include <time.h>
/* Description: This program will assign a random number to the variable n*/

/* betty style doc for function main: if function */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n > 0)
	{
		printf("%d is positive", n);
	}
	else if (n == 0)
	{
		printf("%d is zero", n);
	}
	else
	{
		printf("%d is negative", n);
	}
	return (0);
}
