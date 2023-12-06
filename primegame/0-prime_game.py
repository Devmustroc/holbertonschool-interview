#!/bin/bash/python3
""" Prime Game """


def isWinner(x, nums):
    """
    Prime Game
    :param x: Number of rounds
    :param nums:  Array of numbers
    :return: Name of the player that won the most rounds
    """
    # Check if the array is empty
    if not nums or x < 1:
        return None
    # Assign the max number in the array to n
    n = max(nums)
    # Create a filter array with True values for each index in the range of n + 1
    filterArr = [True for _ in range(max(n + 1, 2))]
    # Set the first two values in the filter array to False
    for i in range(2, int(pow(n, 0.5)) + 1):
        if not filterArr[i]:  # If the value is already False,
            continue  # continue to the next iteration
        for j in range(i * i, n + 1, i):  # Set all multiples of i to False
            filterArr[j] = False  # Set the value to False
    filterArr[0] = filterArr[1] = False  # Set the first two values to False
    c = 0  # Counter
    for i in range(len(filterArr)):  # Set the value to the number of primes
        if filterArr[i]:  # If the value is True
            c += 1  # Increment the counter
        filterArr[i] = c  # Set the value to the counter
    player1 = 0  # Player 1
    for n in nums:  # Iterate through the array
        player1 += filterArr[n] % 2 == 1  # Increment player 1 if the value is odd
    if player1 * 2 == len(nums):  # If player 1 is equal to half the length of the array
        return None  # Return None
    if player1 * 2 > len(nums):  # If player 1 is greater than half the length of the array
        return "Maria"  # Return Maria
    return "Ben"  # Return Ben
