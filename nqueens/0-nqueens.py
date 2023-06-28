#!/usr/bin/env python3
""" N queens problem """
import sys


def is_safe(board, row, col, N):
    """ Check if it's safe to place a queen at board[row][col] """
    for i in range(col):
        if board[row][i] == 'Q':
            return False

    # Check the upper diagonal on the left side
    i = row
    j = col
    while i >= 0 and j >= 0:
        if board[i][j] == 'Q':
            return False
        i -= 1
        j -= 1

    # Check the lower diagonal on the left side
    i = row
    j = col
    while i < N and j >= 0:
        if board[i][j] == 'Q':
            return False
        i += 1
        j -= 1
    return True


def solve_nqueens_util(board, col, N, solutions):
    """ Solve N Queen problem """

    # Base case: If all queens are placed
    if col == N:
        solution = []
        for i in range(N):
            queen_pos = [i, board[i].index('Q')]
            solution.append(queen_pos)
        solutions.append(solution)
        return

    # Try placing a queen in all rows of the current column
    for i in range(N):
        if is_safe(board, i, col, N):
            # Place the queen
            board[i][col] = 'Q'

            # Recur to place the rest of the queens
            solve_nqueens_util(board, col + 1, N, solutions)

            # Backtrack and remove the queen
            board[i][col] = '.'


def solve_nqueens(N):
    """ Solve N queens problem """
    # Create an empty chessboard
    board = [['.' for _ in range(N)] for _ in range(N)]
    solutions = []

    solve_nqueens_util(board, 0, N, solutions)

    return solutions


def print_solutions(solutions):
    """ Print all solutions """

    for solution in solutions:
        for queen_pos in solution:
            print(queen_pos, end=' ')
        print()
    print()


# Main program
if __name__ == '__main__':
    # Check command line arguments
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = solve_nqueens(N)
    print_solutions(solutions)
