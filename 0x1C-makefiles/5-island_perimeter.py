#!/usr/bin/python3


"""Module for calculating the perimeter of an island on a grid."""


def island_perimeter(grid):
    """
    Calculate the perimeter of an island on a grid.

    Args:
        grid (list of list of int): A 2D grid representing the island.
            Each cell contains either land (1) or water (0).

    Returns:
        int: The perimeter of the island.

    Raises:
        None

    Note:
        This function assumes that the input grid is rectangular
        and represents a valid island, with all land cells forming
        a contiguous shape.
    """

    i = 0
    j = 0
    perimeter = 0

    # Check if the grid is valid
    if grid is None or type(grid) is not list or type(grid[0]) is not list:
        return 0

    # Determine the dimensions of the grid
    length = len(grid)
    length2 = len(grid[0])

    # Iterate over each cell in the grid
    while i < length:
        while j < length2:
            if grid[i][j] == 1:
                if i == 0 or grid[i - 1][j] == 0:
                    perimeter += 1
                if j == 0 or grid[i][j - 1] == 0:
                    perimeter += 1
                if j == length2 - 1 or grid[i][j + 1] == 0:
                    perimeter += 1
                if i == length - 1 or grid[i + 1][j] == 0:
                    perimeter += 1
            j += 1
        j = 0
        i += 1
    return perimeter
