#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 *
 * Description: This program will prints the minimum number of coins.
 * the result of the multiplication, followed by a new line
 * @argc: the number of argument
 * @argv: the array of argument
 *
 * Return: 0 if it is Success or 1 does not receive two arguments
 */
int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int i, j;

		int nary = atoi(argv[1]);

		int a = 0;

		int ary[] = {25, 10, 5, 2, 1};

		for (i = 0; i < 5; i++)
		{
			if (nary >= ary[i])
			{
				a = a + nary / ary[i];
				nary = nary % ary[i];
				if (nary % ary[i] == 0)
				{
					break;
				}

			}
		}
		printf("%d\n", a);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}
