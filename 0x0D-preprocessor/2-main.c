#include <stdio.h>

/**
 * main - Entery point
 * Description: prints the name of the
 * file it was compiled from, followed by a new line
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	printf("%s", __FILE__);
}
