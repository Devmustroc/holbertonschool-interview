#!/usr/bin/python3
"""
0-lockboxes.py
Method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    n = len(boxes)
    opened_boxes = {0}  # start with the first box opened
    # repeat until we cannot open any more boxes
    while True:
        num_opened_boxes = len(opened_boxes)
        for i in range(n):
            if i in opened_boxes:  # check if we have the key for this box
                opened_boxes |= set(boxes[i])
        if len(opened_boxes) == num_opened_boxes:
            break  # no more boxes can be opened
    return len(opened_boxes) == n  # check if all boxes are opened
