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
	size_t start, end;
	int temp;

	if (array == NULL || size <= 1)
		return;

	for (start = (size - 2) / 2; (int)start >= 0; start--)
		sift_down(array, size, start, size - 1);

	for (end = size - 1; end > 0; end--)
	{
		temp = array[0];
		array[0] = array[end];
		array[end] = temp;
		print_array(array, size);
		sift_down(array, size, 0, end - 1);
	}
}
