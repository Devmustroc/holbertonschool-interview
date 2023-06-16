#include "menger.h"
/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 * Return: void
 */

void drawMenger(int level, int x, int y, int size)
{
    if (level == 0)
    {
        printf("#");
        return;
    }
    int newSize = size / 3;
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
                printf(" ");
            else
                drawMenger(level - 1, x + i * newSize, y + j * newSize, newSize);
        }
    }
}
/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 * Return: void
 */
void menger(int level)
{
    if (level < 0)
        return;
    int size = pow(3, level);
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            drawMenger(level, i, j, size);
        }
        printf("\n");
    }
}
