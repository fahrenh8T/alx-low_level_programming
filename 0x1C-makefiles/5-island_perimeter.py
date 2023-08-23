#!/usr/bin/python3
'''defines an island perimeter measuring function
'''


def island_perimeter(grid):
    '''calculate the perimeter of an island based on a 2D grid

        Args:
        grid (list[list[int]]): A 2D grid representing the island

        the function assumes that the input grid is rectangular and valid
        the function uses the formula: perimeter = size * 4 - edges * 2
    '''
    width = len(grid[0])
    height = len(grid)
    edges = 0
    size = 0

    for ind in range(height):
        for jnd in range(width):
            if grid[ind][jnd] == 1:
                size += 1

                if (jnd > 0 and grid[ind][jnd - 1] == 1):
                    edges += 1
                if (ind > 0 and grid[ind - 1][jnd] == 1):
                    edges += 1

    perimeter = (size * 4) - (edges * 2)
    return perimeter
