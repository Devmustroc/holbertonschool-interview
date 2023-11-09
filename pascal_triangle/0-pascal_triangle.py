#!/usr/bin/python3
"""
0-pascal_triangle
"""


def pascal_triangle(n):
    """
    Returns a list of lists of integers representing the Pascal’s triangle of n
    """
    # Check if n is less than or equal to 0
    if n <= 0:
        # If true, return an empty list since Pascal's triangle for n <= 0 is empty
        return []

    # Initialize the triangle with the first row containing only 1
    triangle = [[1]]

    # Iterate from the second row to the nth row
    for i in range(1, n):
        # Initialize a new row with the first element as 1
        row = [1]

        # Iterate from the second element to the (i-1)-th element in the current row
        for j in range(1, i):
            # Calculate the value by adding the two diagonal elements from the previous row
            row.append(triangle[i - 1][j - 1] + triangle[i - 1][j])

        # Add the last element of the row, which is always 1
        row.append(1)

        # Add the newly constructed row to the triangle
        triangle.append(row)

    # Return the Pascal's triangle up to the nth row
    return triangle
