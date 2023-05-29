#include "slide_line.h"
/**
 * merge_values - Merges the values in the line towards the left direction
 *
 * @line: Pointer to the array of integers representing the line
 * @size: Number of elements in the line
 */
void merge_values(int *line, size_t size)
{
	size_t i, merge_index = 0;
	int merged[size];

	for (i = 0; i < size; i++)
		merged[i] = 0;

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

	for (i = merge_index; i < size; i++)
		line[i] = 0;
}
/**
 * slide_line - Slide and merge the line in the specified direction
 *
 * @line: Pointer to the array of integers representing the line
 * @size: Number of elements in the line
 * @direction: Direction of the slide (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_LEFT)
		merge_values(line, size);
	else
	{
		size_t i, j;
		int temp;

		for (i = 0, j = size - 1; i < j; i++, j--)
		{
			temp = line[i];
			line[i] = line[j];
			line[j] = temp;
		}
		merge_values(line, size);

		for (i = 0, j = size - 1; i < j; i++, j--)
		{
			temp = line[i];
			line[i] = line[j];
			line[j] = temp;
		}
	}
	return (1);
}
