#ifndef _SLIDE_LINE_H_
#define _SLIDE_LINE_H_
#define SLIDE_LEFT 1
#define SLIDE_RIGHT 2

#include <stdlib.h>
#include <stdio.h>

void slide_left(int *line, size_t size);
void slide_right(int *line, size_t size);
int slide_line(int *line, size_t size, int direction);


#endif
