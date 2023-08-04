#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - prints an array of integers
 * @array: pointer to the first element of the array to print
 * @left: leftmost index of the subarray
 * @right: rightmost index of the subarray
 */
void print_array(int *array, int left, int right)
{
	int i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}
/**
 * advanced_binary_recursive - recursive function to search for a value
 * @array: pointer to the first element of the array to search in
 * @low: leftmost index of the subarray
 * @high: rightmost index of the subarray
 * @value: value to search for
 * Return: index where value is located, or -1 if not found
*/
int advanced_binary_recursive(int *array, int low, int high, int value)
{
	int mid;

	if (low > high)
		return (-1);

	print_array(array, low, high);

	mid = low + (high - low) / 2;

	if (array[mid] == value && (mid == 0 || array[mid - 1] < value))
		return (mid);
	else if (array[mid] < value)
		return (advanced_binary_recursive(array, mid + 1, high, value));
	else if (array[mid] >= value)
		return (advanced_binary_recursive(array, low, mid, value));
	return (-1);
}
/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: index where value is located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
	{
		return (-1);
	}
	return (advanced_binary_recursive(array, 0, size - 1, value));
}
