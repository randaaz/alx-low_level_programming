#include "main.h"

/**
 * main - Entry point
 *
 * Description: prints _putchar, followed by a new line
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	char ran[] = "_putchar";
	int i;

	for (i = 0; i < 8; i++)
		_putchar(ran[i]);
	_putchar('\n');
	return (0);
}
