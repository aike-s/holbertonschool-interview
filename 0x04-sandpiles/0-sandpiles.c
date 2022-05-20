#include "sandpiles.h"

/* Necesary functions */

int unstable_grid(int grid[3][3]);
void add_around(int grid[3][3], int i, int j);
void print_and_copy_grid(int grid[3][3], int copy_grid[3][3]);

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first grid
 * @grid2: second grid
 * Return: Always void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int copy_grid[3][3];

	/* Sum the grids */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			copy_grid[i][j] = grid1[i][j];
		}
	}

	/* While the grid is unestable, do... */
	while (unstable_grid(grid1))
	{
		printf("=\n");
		print_and_copy_grid(grid1, copy_grid);

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (copy_grid[i][j] > 3)
				{
					grid1[i][j] -= 4;
					add_around(grid1, i, j);
				}
			}
		}
	}
}

/**
 * unstable_grid - checks if a grid is unstable
 * @grid: grid to check
 * Return: 0 if it is or -1 otherwise
 */
int unstable_grid(int grid[3][3])
{
	int i, j, sandgrain = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			sandgrain = grid[i][j];

			if (sandgrain > 3)
				return (1);
		}
	}

	return (0);
}

/**
 * add_around - Sum 1 around the actual index
 * @grid: grid to run along
 * @i: first index
 * @j: second index
 * Return: always void
 */
void add_around(int grid[3][3], int i, int j)
{
	int up = i - 1, down = i + 1;
	int left = j - 1, right = j + 1;

	if (up >= 0)
		grid[up][j] += 1;

	if (down < 3)
		grid[down][j] += 1;

	if (left >= 0)
		grid[i][left] += 1;

	if (right < 3)
		grid[i][right] += 1;

}

/**
 * print_and_copy_grid - Copy and print 3x3 grid
 * @grid: 3x3 grid
 * @copy_grid: copy of original grid
 * Return - Always void
 */
void print_and_copy_grid(int grid[3][3], int copy_grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			copy_grid[i][j] = grid[i][j];

			if (j)
				printf(" ");

			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
