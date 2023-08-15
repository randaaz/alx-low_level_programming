#include <stdio.h>

/**
 * main - Entry point
 *
 * Description:  prints _putchar, followed by a new line
 *
 * Return: Always 0 (Success)
*/

void prints(void);

int main(void)
{
	prints();
	putchar('\n');
	return (0);
}

void prints(void)
{
	putchar('_');
	putchar('p');
	putchar('u');
	putchar('t');
	putchar('c');
	putchar('h');
	putchar('a');
	putchar('r');
}
