#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - allocates a 2D grid of integers
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: pointer to a 2 dimensional array of integers
 */
int **alloc_grid(int width, int height)
{
	int **new;
	int i, j;

	if (height <= 0 || width <= 0)
	{
		return (NULL);
	}

	new = malloc(sizeof(int *) * height);

	if (new == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < height; i++)
	{
		new[i] = (int *)malloc(sizeof(int) * width);

		if (new[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(new[j]);
			}
			free(new);
			return (NULL);
		}
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			new[i][j] = 0;
		}
	}

	return (new);
}
