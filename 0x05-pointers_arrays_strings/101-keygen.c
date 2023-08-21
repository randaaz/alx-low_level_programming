#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point
 *
 * Description: generates random valid passwords for the program 101-crackme
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	int pass;
	int sn;

	srand(time(NULL));
	sn = 0;
	while (sn <= 2645)
	{
		pass = (rand() % (128 - 23) + 32);
			sn += pass;
		putchar(pass);
	}
	putchar(2772 - sn);
	putchar('\n');
	return (0);
}
