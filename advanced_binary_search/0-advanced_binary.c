#include "search_algos.h"
#include <stdio.h>
/**
* advanced_binary - searches for a value in a sorted array of integers.
 * @array: pointer to the first element of the array to search in.
 * @size: number of elements in array.
 * @value: value to search for.
 * Return: index where value is located or -1 if value is not present or array
*/
int advanced_binary(int *array, size_t size, int value) {
    size_t i = 0, j = size - 1, m = 0, k = 0;
    int tmp = 0;
    if (array == NULL || size == 0)
        return (-1);
    while (i <= j) {
        printf("Searching in array: ");
        for (k = i; k < j; k++)
            printf("%d, ", array[k]);
        printf("%d\n", array[k]);
        m = (i + j) / 2;
        if (array[m] < value)
            i = m + 1;
        else if (array[m] > value)
            j = m;
        else {
            if (m == 0 || array[m - 1] != value)
                return (m);
            j = m;
        }
    }
    return (-1);
}