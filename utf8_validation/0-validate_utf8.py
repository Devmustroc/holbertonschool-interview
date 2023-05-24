#!/usr/bin/python3
"""UTF-8 Validation"""


def validUTF8(data):
    num_bytes = 0  # Number of bytes in the current character

    for num in data:
        # Check if the current byte is a continuation byte
        if num & 0b11000000 == 0b10000000:
            if num_bytes == 0:
                return False  # Unexpected continuation byte
            num_bytes -= 1
        else:
            if num_bytes != 0:
                return False  # Incomplete character
            if num & 0b10000000 == 0:
                num_bytes = 0  # ASCII character
            elif num & 0b11100000 == 0b11000000:
                num_bytes = 1  # Character with 2 bytes
            elif num & 0b11110000 == 0b11100000:
                num_bytes = 2  # Character with 3 bytes
            elif num & 0b11111000 == 0b11110000:
                num_bytes = 3  # Character with 4 bytes
            else:
                return False  # Invalid leading byte

    return num_bytes == 0
