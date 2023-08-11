#include <unistd.h>
/**
 * main - Entry point
 * Description: Write a program print without usei any functios
 *
 * Return: 1 (not Scuccess)
*/
int main(void)
{
	char ran[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	write(1, ran, 59);
	return (1);
}
