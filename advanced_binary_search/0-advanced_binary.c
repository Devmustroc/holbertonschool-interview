#include "search_algos.h"
#include <stdio.h>
/**
 * advanced_binary_recursive - recursive function to search for a value
 * @array: pointer to the first element of the array to search in
 * @left: leftmost index of the subarray
 * @right: rightmost index of the subarray
 * @value: value to search for
 * Return: index where value is located, or -1 if not found
*/
int advanced_binary_recursive(int *array, int left, int right, int value)
{
	int mid, i;

	if (left > right)
		return (-1);

	mid = (left + right) / 2;
	printf("Searching in array: ");

	i = left;

	while (i <= right)
	{
		printf("%d", array[i]);
		if (i != right)
			printf(", ");
		i++;
	}
	printf("\n");

	if (array[mid] == value)
	{
		if (mid == left || array[mid - 1] != value)
			return (mid);
		else
			return (advanced_binary_recursive(array, left, mid - 1, value));
	}
	else if (array[mid] < value)
	{
		return (advanced_binary_recursive(array, mid + 1, right, value));
	}
	else
	{
		return (advanced_binary_recursive(array, left, mid - 1, value));
	}
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
