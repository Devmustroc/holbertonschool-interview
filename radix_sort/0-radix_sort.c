#include "sort.h"
/**
 * find_max - find the max value in an array
 * @param array: array to search
 * @param size: size of array
 * @return: max value
 */

int find_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return (max);
}

/**
 * counting_sort - sort an array using counting sort algorithm
 * @param array: array to sort
 * @param size: size of array
 * @param exp: exponent
 */
void counting_sort(int *array, size_t size, int exp)
{
    int *output = malloc(sizeof(int) * size);
    int count[10] = {0};

    for (int i = 0; i < (int)size; i++)
        count[(array[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = (int)size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (int i = 0; i < (int)size; i++)
        array[i] = output[i];

    free(output);
}

/**
 * radix_sort - sort an array using radix sort algorithm
 * @param array: array to sort
 * @param size: size of array
 */
void radix_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int max = find_max(array, size);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort(array, size, exp);
        print_array(array, size);
    }
}