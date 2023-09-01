#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: This program will prints the number of arguments passed into it
 * @argc: the number of argument
 * @argv: the array of argument
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	(void)argv;
	printf("%d \n", argc - 1);
	return (0);
}
