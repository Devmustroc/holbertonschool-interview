#!/usr/bin/python3

def rotate_2d_matrix(matrix):
    n = len(matrix)
    for layer in range(n // 2):
        first = layer
        last = n - 1 - layer
        for i in range(first, last):
            temp = matrix[first][i]
            matrix[first][i] = matrix[last - i][first]
            matrix[last - i][first] = matrix[last][last - i]
            matrix[last][last - i] = matrix[i][last]
            matrix[i][last] = temp
