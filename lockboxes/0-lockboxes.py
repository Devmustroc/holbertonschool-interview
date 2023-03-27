#!/usr/bin/python3
"""
0-lockboxes.py
Method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """Unlock array of boxes of keys with indices"""
    idx = 0
    size = len(boxes)
    check = {}

    for ks in boxes:
        if len(ks) == 0 or idx == 0:
            check[idx] = -1
        for key in ks:
            if key < size and key != idx:
                check[key] = key
        if len(check) == size:
            return True
        idx += 1

    return False