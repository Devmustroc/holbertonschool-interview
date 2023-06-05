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
        int i, j, merged;

        for (i = 0; i < (int)size; i++) {
            merged = 0;

            if (line[i] == 0)
                continue;

            for (j = i + 1; j < (int)size; j++) {
                if (line[j] == 0)
                    continue;

                if (line[i] == line[j]) {
                    line[i] *= 2;
                    line[j] = 0;
                    merged = 1;
                }

                break;
            }

            if (merged)
                continue;

            for (j = i - 1; j >= 0; j--) {
                if (line[j] != 0)
                    break;

                line[j] = line[i];
                line[i] = 0;
                i = j;
            }
        }
    } else if (direction == SLIDE_RIGHT) {
        int i, j, merged;

        for (i = (int)size - 1; i >= 0; i--) {
            merged = 0;

            if (line[i] == 0)
                continue;

            for (j = i - 1; j >= 0; j--) {
                if (line[j] == 0)
                    continue;

                if (line[i] == line[j]) {
                    line[i] *= 2;
                    line[j] = 0;
                    merged = 1;
                }

                break;
            }

            if (merged)
                continue;

            for (j = i + 1; j < (int)size; j++) {
                if (line[j] != 0)
                    break;

                line[j] = line[i];
                line[i] = 0;
                i = j;
            }
        }
    }

    return 1;
}
