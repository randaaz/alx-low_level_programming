#include <stdio.h>
/**
 * main - Entry point
 * Description: Write a c program print without use  any functions listed in the NAME section of the man (3) printf or man (3) puts
 *
 * Return: Always 1 (not Scuccess)
*/
int main(void)
{
	char quote[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	write(1,quote,59);
	return (1);
}
