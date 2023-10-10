#ifndef RADIX_SORT_SORT_H
#define RADIX_SORT_SORT_H

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void counting_sort(int *array, size_t size, int exp);
void radix_sort(int *array, size_t size);
int find_max(int *array, size_t size);

#endif
