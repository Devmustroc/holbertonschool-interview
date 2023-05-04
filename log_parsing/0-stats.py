#!/usr/bin/python3
"""
This script reads from the standard input line by line and computes metrics.
"""

from sys import stdin


STATUS_CODES = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}

SIZE = 0


def print_stats():
    """
    Prints the accumulated logs.
    """
    print(f"File size: {SIZE}")
    for status in sorted(STATUS_CODES.keys()):
        if STATUS_CODES[status] != 0:
            print(f"{status}: {STATUS_CODES[status]}")


if __name__ == "__main__":
    count = 0
    try:
        for line in stdin:
            try:
                data = line.split()
                SIZE += int(data[-1])
                if data[-2] in STATUS_CODES:
                    STATUS_CODES[data[-2]] += 1
            except:
                pass
            if count == 9:
                print_stats()
                count = -1
            count += 1
    except KeyboardInterrupt:
        print_stats()
        raise
    print_stats()
