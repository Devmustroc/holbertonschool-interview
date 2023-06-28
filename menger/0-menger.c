#include "menger.h"
/**
 * draw_char - draws a character
 * @row: row
 * @col: column
 * @size: size
 */
void draw_char(int row, int col, int size)
{
    /* if row or column is 1, print a space */
    for (int i = 0; i < size; i++)
    {
        if (row % 3 == 1 && col % 3 == 1)
        {
            printf(" ");
        }
        else
        {
            printf("#");
        }
        row /= 3;
        col /= 3;
    }
}
/**
 * draw_menger - draws a menger sponge
 * @level: level
 * @row: row
 * @col: column
 * @size: size
 */
void draw_menger(int level, int row, int col, int size)
{
    /* if level is 0, print a 1x1 block */
    if (level == 0)
    {
        draw_char(row, col, size);
    }
    /* if level is greater than 0, print a 3x3 block */
    else
    {
        int newSize = size / 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j< 3; j++)
            {
                int newRow = row + i * newSize;
                int newCol = col + j * newSize;
                /* if it's the middle block, print a space */
                draw_menger(level - 1, newRow, newCol, newSize);
            }
        }
    }
}
/**
 * menger - draws a menger sponge
 * @level: level
 */
void menger(int level)
{
    /* if level is less than 0, do nothing */
    if (level < 0)
    {
        return;
    }
    /* if level is 0, print a 1x1 block */
    int size = pow(3, level);
    /* if level is 0, print a 1x1 block */
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j< size; j++)
        {
            draw_char(i, j, size);
            printf("\n");
        }
    }
}