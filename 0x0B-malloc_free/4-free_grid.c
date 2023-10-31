#include "main.h"

/**
 * free_grid - frees memory for a 2D grid
 *
 * @grid: pointer to 2D array
 * @height: height of the array
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; ++i)
	{
		free(grid[i]);
	}

	free(grid);
}
