#include "sort.h"

/**
 * sift_down - Perform the sift-down operation in the heap sort algorithm
 *
 * @array: The array to be sorted
 * @size: Size of the array
 * @start: Index of the root of the heap
 * @end: Index of the end of the heap
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start;
	size_t child;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		if (child + 1 <= end && array[child] < array[child + 1])
			child++;

		if (array[root] < array[child])
		{
			int tmp = array[root];

			array[root] = array[child];
			array[child] = tmp;
			print_array(array, size);
			root = child;
		}
		else
			return;
	}
}
/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	size_t start = (size - 2) / 2;
	size_t end = size - 1;

	while (start > 0)
	{
		sift_down(array, size, start, end);
		start--;
	}
	sift_down(array, size, start, end);

	while (end > 0)
	{
		int tmp = array[end];

		array[end] = array[0];
		array[0] = tmp;
		print_array(array, size);
		end--;
		sift_down(array, size, start, end);
	}
}
