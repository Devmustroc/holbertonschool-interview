#!/usr/bin/python3
"""
Module that parses a log and prints stats to stdout
"""
import sys  # for stdin


if __name__ == "__main__":  # main guard
    st_code = {"200": 0,
               "301": 0,
               "400": 0,
               "401": 0,
               "403": 0,
               "404": 0,
               "405": 0,
               "500": 0}
    count = 1  # count of lines
    file_size = 0  # total file size

    def parse_line(line): # parse line
        """ Read, parse and grab data"""
        try:
            parsed_line = line.split()  # split line
            status_code = parsed_line[-2]  # grab status code
            if status_code in st_code.keys():  # if status code in dict
                st_code[status_code] += 1  # increment
            return int(parsed_line[-1])  # return file size
        except Exception:  # if error
            return 0

    def print_stats():
        """print stats in ascending order"""
        print(f"File size: {file_size}")  # print file size
        for key in sorted(st_code.keys()):  # print status codes
            if st_code[key]: # if status code in dict
                print(f"{key}: {st_code[key]}")  # print status code and count

    try:  # try to read stdin
        for line in sys.stdin:  # read line by line
            file_size += parse_line(line)  # increment file size
            if count % 10 == 0:  # print stats every 10 lines
                print_stats()  # print stats
            count += 1  # increment count
    except KeyboardInterrupt:  # if keyboard interrupt
        print_stats()  # print stats
        raise  # raise error
    print_stats()  # print stats

