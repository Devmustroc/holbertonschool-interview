#include <stdio.h>

int advanced_binary_recursive(int *array, int left, int right, int value)
{
	if (left > right)
		return -1;

	int mid = (left + right) / 2;

	printf("Searching in array: ");
	for (int i = left; i <= right; i++)
	{
		printf("%d", array[i]);

		if (i != right)
			printf(", ");
	}
	printf("\n");

	if (array[mid] == value)
	{
		if (mid == left || array[mid - 1] != value)
			return mid;
		else
			return advanced_binary_recursive(array, left, mid - 1, value);
	}
	else if (array[mid] < value)
	{
		return advanced_binary_recursive(array, mid + 1, right, value);
	}
	else
	{
		return advanced_binary_recursive(array, left, mid - 1, value);
	}
}
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return -1;

	return advanced_binary_recursive(array, 0, size - 1, value);
}
