#!/usr/bin/python3
"""
Calculates the sum of prime factors of a given positive integer.
Args:
    n (int): A positive integer to find the sum of prime factors of.
Returns:
    int: The sum of prime factors of the given integer.
"""


def minOperations(n):
    # If n is less than or equal to 1, return 0
    if n <= 1:
        return 0
    # Initialize "i" to 2 and count to 0
    i = 2
    # While "i" is less than or equal to n
    count = 0

    while i <= n:  # while "i" is less than or equal to n
        if n % i == 0:  # if n is divisible by "i"
            n /= i  # n = n / "i"
            count += i  # count = count + "i"
        else:
            i += 1
    return count  # return count
