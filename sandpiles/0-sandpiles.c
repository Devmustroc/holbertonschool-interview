#include "sandpiles.h"
/**
 * sandpiles_sum - sums two sandpiles and topples until sum is stable
 * @grid1: first 3x3 grid of integers to sum, assumed to be stable
 * @grid2: second 3x3 grid of integers to sum, assumed to be stable
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j; /* iterators */
	int flags[3][3] = { /* flags for unstable cells */
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	for (i = 0; i < 3; i++) /* add grid2 to grid1 */
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j]; /* add grid2 to grid1 */
		}
	}
	while (grid1_unstable(grid1, flags)) /* while unstable */
	{
		/* print unstable grid before topple round */
		printf("=\n"); /* print separator */
		print_grid(grid1); /* print unstable grid */
		for (i = 0; i < 3; i++) /* topple unstable cells */
		{
			for (j = 0; j < 3; j++) /* topple unstable cells */
			{
				if (flags[i][j]) /* if unstable */
					topple(grid1, i, j); /* topple */
			}
		}
	}
}

/**
* grid1_unstable - checks stability of grid and sets flags where unstable
 * grid is unstable if any cell is greater than 3
 * @grid1: 3x3 grid of integers to check stability
 * @flags: 3x3 grid indicating unstable cells
 *
 * Return: 1 if unstable, 0 otherwise
 */
int grid1_unstable(int grid1[3][3], int flags[3][3])
{
	int i, j; /* iterators */
	int unstable = 0; /* flag for unstable grid */

	for (i = 0; i < 3; i++) /* check for unstable cells */
	{
		for (j = 0; j < 3; j++) /* check for unstable cells */
		{
			if (grid1[i][j] > 3) /* if unstable */
			{
				flags[i][j] = 1; /* set flag */
				unstable = 1; /* set flag */
			}
			else /* if stable */
				flags[i][j] = 0; /* clear flag */
		}
	}
	return (unstable); /* return if unstable */
}
/**
 * topple - topples unstable cell and distributes sand to neighbors
 * @grid1: 3x3 grid of integers to topple
 * @i: row of cell to topple
 * @j: column of cell to topple
 */
void topple(int grid1[3][3], int i, int j)
{
	grid1[i][j] -= 4; /* topple cell */

	if (i - 1 >= 0) /* if neighbor exists */
		grid1[i - 1][j] += 1; /* add sand */
	if (i + 1 < 3) /* if neighbor exists */
		grid1[i + 1][j] += 1; /* add sand */
	if (j - 1 >= 0) /* if neighbor exists */
		grid1[i][j - 1] += 1; /* add sand */
	if (j + 1 < 3) /* if neighbor exists */
		grid1[i][j + 1] += 1; /* add sand */
}
/**
 * print_grid - prints a 3x3 grid of integers
 * @grid: 3x3 grid of integers to print
 */
void print_grid(int grid[3][3])
{
	int i, j; /* iterators */

	for (i = 0; i < 3; i++) /* print grid */
	{
		for (j = 0; j < 3; j++) /* print grid */
		{
			if (j) /* if not first column */
				printf(" "); /* print space */
			printf("%d", grid[i][j]); /* print cell */
		}
		printf("\n"); /* print newline */
	}
}
