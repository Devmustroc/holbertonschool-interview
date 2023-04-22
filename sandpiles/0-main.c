#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * print_grid_sum - Print 3x3 grids sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
static void print_grid_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;  /* iterators */

    for (i = 0; i < 3; i++) /* check for unstable cells */
    {
        for (j = 0; j < 3; j++) /* check for unstable cells */
        {
            if (j) /* if not first column */
                printf(" "); /* print space */
            printf("%d", grid1[i][j]); /* print grid1 */
        }

        printf(" %c ", (i == 1 ? '+' : ' ')); /* print operator */

        for (j = 0; j < 3; j++)     /* check for unstable cells */
        {
            if (j) /* if not first column */
                printf(" "); /* print space */
            printf("%d", grid2[i][j]); /* print grid2 */
        }
        printf("\n"); /* print newline */
    }
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3]) /* print 3x3 grid */
{
    int i, j; /* iterators */

    for (i = 0; i < 3; i++) /* check for unstable cells */
    {
        for (j = 0; j < 3; j++) /* check for unstable cells */
        {
            if (j) /* if not first column */
                printf(" "); /* print space */
            printf("%d", grid[i][j]);   /* print grid */
        }
        printf("\n"); /* print newline */
    }
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    int grid1[3][3] = { /* first grid */
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    };
    int grid2[3][3] = { /* second grid */
            {3, 3, 3},
            {3, 3, 3},
            {3, 3, 3}
    };

    print_grid_sum(grid1, grid2); /* print grids before sum */

    sandpiles_sum(grid1, grid2); /* sum grids */

    printf("=\n"); /* print separator */
    print_grid(grid1); /* print grid after sum */

    return (EXIT_SUCCESS);
}