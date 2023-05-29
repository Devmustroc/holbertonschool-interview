#ifndef _SLIDE_LINE_H_
#define _SLIDE_LINE_H_
#define SLIDE_LEFT 1
#define SLIDE_RIGHT 2

#include <stdlib.h>
#include <stdio.h>

void merge_values(int *line, size_t size);
int slide_line(int *line, size_t size, int direction);

#endif
