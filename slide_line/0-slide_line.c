#include "slide_line.h"

/**
 * Slide and merge an array of integers to the left or right.
 *
 * @param line      Pointer to an array of integers.
 * @param size      Number of elements in the array.
 * @param direction Direction to slide and merge (SLIDE_LEFT or SLIDE_RIGHT).
 *
 * @return 1 on success, 0 on failure.
 */
int slide_line(int *line, size_t size, int direction) {
    if (line == NULL || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return 0;

    if (size < 2)
        return 1;

    if (direction == SLIDE_LEFT) {
        int i, j;
        int merged = 0;

        for (i = 0; i < (int)size; i++) {
            if (line[i] == 0)
                continue;

            if (merged && line[i] == line[j - 1]) {
                line[j - 1] *= 2;
                line[i] = 0;
                merged = 0;
            } else {
                line[j++] = line[i];
                if (j - 1 != i)
                    line[i] = 0;
                merged = 0;
            }
        }
    } else if (direction == SLIDE_RIGHT) {
        int i, j;
        int merged = 0;

        for (i = (int)size - 1, j = i; i >= 0; i--) {
            if (line[i] == 0)
                continue;

            if (merged && line[i] == line[j + 1]) {
                line[j + 1] *= 2;
                line[i] = 0;
                merged = 0;
            } else {
                line[j--] = line[i];
                if (j + 1 != i)
                    line[i] = 0;
                merged = 0;
            }
        }
    }

    return 1;
}
