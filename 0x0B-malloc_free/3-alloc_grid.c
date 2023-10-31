#include "main.h"

/**
 * alloc_grid -  returns a pointer to a 2D array of integers.
 *
 * @width: width of grid (rows)
 * @height: height of grid (columns)
 *
 * Return: pointer to the 2D grid of integers, NULL if it fails
 */

int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j, k, l;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}

	grid = (int **)malloc(height * sizeof(int *));
	if (grid == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < height; ++i)
	{
		grid[i] = (int *)malloc(width * sizeof(int));
		if (grid[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(grid[j]);
			}
			free(grid);
			return (NULL);
		}
	}

	for (k = 0; k < height; ++k)
	{
		for (l = 0; l < width; ++l)
			grid[k][l] = 0;
	}

	return (grid);
}
