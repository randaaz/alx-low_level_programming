#include <stdlib.h>

#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: This program will prints
 * the result of the multiplication, followed by a new line
 * @argc: the number of argument
 * @argv: the array of argument
 *
 * Return: 0 if it is Success or 1 does not receive two arguments
 */
int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		int multiply = atoi(argv[1]) * atoi(argv[2]);

		printf("%d \n", multiply);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}
