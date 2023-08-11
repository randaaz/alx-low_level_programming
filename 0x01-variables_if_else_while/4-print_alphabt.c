#include <stdio.h>

/**
 * main - Entry point
 * Description: using while loop and if founction
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
        char alphabet = 'a';

        while (alphabet <= 'z')
        {
		if (alphabet != 'q' && alphabet != 'e' )
		{
                putchar(alphabet);
		}
                alphabet++;
        }
        putchar('\n');

        return (0);
}
