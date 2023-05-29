#include "slide_line.h"
/**
 * slide_left - Slide and merge the line to the left
 *
 * @line: Pointer to the array of integers representing the line
 * @size: Number of elements in the line
 */
void slide_left(int *line, size_t size)
{
    size_t i, j;
    int merged[32] = {0};
    int merge_index = 0;

    for (i = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            if (merge_index > 0 && line[i] == merged[merge_index - 1])
            {
                line[i] *= 2;
                merged[merge_index - 1] = line[i];
            }
            else
            {
                line[merge_index] = line[i];
                merge_index++;
            }
        }
    }

    for (j = merge_index; j < size; j++)
        line[j] = 0;
}
/**
 * slide_right - Slide and merge the line to the right
 *
 * @line: Pointer to the array of integers representing the line
 * @size: Number of elements in the line
 */
void slide_right(int *line, size_t size)
{
    size_t i;
    int temp[32] = {0};

    for (i = 0; i < size; i++)
        temp[i] = line[size - 1 - i];

    slide_left(temp, size);

    for (i = 0; i < size; i++)
        line[i] = temp[size - 1 - i];
}
/**
 * slide_line - Slide and merge an array of integers
 *
 * @line: Pointer to the array of integers representing the line
 * @size: Number of elements in the line
 * @direction: Direction to slide and merge the line
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    if (line == NULL || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return 0;

    if (direction == SLIDE_LEFT)
        slide_left(line, size);
    else
        slide_right(line, size);

    return 1;
}
