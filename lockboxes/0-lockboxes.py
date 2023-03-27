#!/usr/bin/python3
"""
0-lockboxes.py
Method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """Unlock array of boxes of keys with indices"""
    idx = 0  # Start with the first box (index 0)
    size = len(boxes)  # Get the number of boxes in the input array
    check = {}  # Create an empty dictionary to keep track of which boxes can be opened

    for ks in boxes:  # Loop through each box in the input array
        if len(ks) == 0 or idx == 0:  # If the box is empty or it's the first box (which is already open)
            check[idx] = -1  # Mark the box as empty in the checker dictionary (-1 means empty)
        for key in ks:  # Loop through each key in the current box
            if key < size and key != idx:  # If the key is valid (i.e. it corresponds to a box in the input array), and it doesn't open the current box
                check[key] = key  # Mark the corresponding box as open in the checker dictionary
        if len(check) == size:  # If all boxes have been marked as open in the checker dictionary
            return True  # Return True (i.e. all boxes can be opened)
        idx += 1  # Move on to the next box

    return False  # If we reach this point, we were not able to open all boxes, so return False