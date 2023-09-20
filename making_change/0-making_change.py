#!/usr/bin/python3
"""
making change
"""


def makeChange(coins, total):
    """Given a pile of coins of different values,
     determine the fewest number
    of coins needed to meet a given amount total.
    """
    if total <= 0:
        return 0

    coins.sort(reverse=True)
    count = 0

    for coin in coins:
        if total <= 0:
            break
        if total >= coin:
            num_coins = total // coin
            count += num_coins
            total -= num_coins * coin

    # Check if total is not zero after processing all coins.
    if total != 0:
        return -1

    return count