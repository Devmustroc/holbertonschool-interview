#!/usr/bin/python3
"""
making change
"""


def makeChange(coins, total):
    """Given a pile of coins of different values,
     determine the fewest number
    of coins needed to meet a given amount total.
    """
    if total < 1:
        return 0

    dq = [0] + [-1 for i in range(1, total + 1)]

    for i in coins:
        if i > total:
            continue
        dq[i] = 1
        for j in range(i + 1, total + 1):
            if dq[j - i] > 0:
                if dq[j] == -1:
                    dq[j] = dq[j - i] + 1
                else:
                    dq[j] = min(dq[j - i] + 1, dq[j])
    return dq[total]
