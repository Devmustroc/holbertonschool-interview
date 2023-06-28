#include "menger.h"
void draw_char(int row, int col, int size)
{
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
void draw_menger(int level, int row, int col, int size)
{
    if (level == 0)
    {
        draw_char(row, col, size);
    }
    else
    {
        int newSize = size / 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j< 3; j++)
            {
                int newRow = row + i * newSize;
                int newCol = col + j * newSize;
                draw_menger(level - 1, newRow, newCol, newSize);
            }
        }
    }
}
void menger(int level)
{
    if (level < 0)
    {
        return;
    }
    int size = pow(3, level);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j< size; j++)
        {
            draw_char(i, j, size);
            printf("\n");
        }
    }
}