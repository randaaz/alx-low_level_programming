#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - a keygen for crackme5.
 * @argc: number of arguments.
 * @argv: an array of arguments.
 *
 * Return: Always 0 success.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	char p[7], *cx;
	int l = strlen(argv[1]), j, t;

	cx = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	t = (l ^ 59) & 63;
	p[0] = cx[t];

	t = 0;
	for (j = 0; j < l; j++)
		t += argv[1][j];
	p[1] = cx[(t ^ 79) & 63];

	t = 1;
	for (j = 0; j < l; j++)
		t *= argv[1][j];
	p[2] = cx[(t ^ 85) & 63];

	t = 0;
	for (j = 0; j < l; j++)
	{
		if (argv[1][j] > t)
			t = argv[1][j];
	}
	srand(t ^ 14);
	p[3] = cx[rand() & 63];

	t = 0;
	for (j = 0; j < l; j++)
		t += (argv[1][j] * argv[1][j]);
	p[4] = cx[(t ^ 239) & 63];

	for (j = 0; j < argv[1][0]; j++)
		t = rand();
	p[5] = cx[(t ^ 229) & 63];

	p[6] = '\0';
	printf("%s", p);
	return (0);
}
