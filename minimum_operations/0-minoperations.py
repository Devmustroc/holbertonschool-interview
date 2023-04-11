#!/usr/bin/python3

def minOperations(n):
    """
        Calculates the sum of prime factors of a given positive integer.

        Args:
        n (int): A positive integer to find the sum of prime factors of.

        Returns:
        int: The sum of prime factors of the given integer.
    """
    if n <= 1:
        return 0
    i = 2
    count = 0
    while i <= n:
        if n % i == 0:
            n /= i
            count += i
        else:
            i += 1
    return count