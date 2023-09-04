#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2D grid previously created by alloc_grid
 * @grid: pointer to the 2D array to be freed
 * @height: height of the grid
 */

void free_grid(int **grid, int height)
{
	unsigned int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);

}
