from collections import defaultdict
from typing import List

import numpy as np


class EqualPairs(object):
    """
    Given a `n x  n` matrix of positive integers, return the number of pairs `(r_i, c_i)` such that row `r_i` and column `c_i` are equal.
    A row and column pair are considered equal if they contian the same elements in the same order, i.e., they are equal arrays.

    Parameters
    ----------
    grid : List[List[int]]
        A 2-D array represnted by a list of lists

    Returns
    -------
    int
        Number of equal pairs
    """

    @staticmethod
    def numpy(grid: List[List[int]]) -> int:
        if len(grid) == 1:
            return 1
        # Convert to numpy array
        matrix = np.array(grid)
        # Rows hash map
        row_counts = defaultdict(int)
        for row in matrix:
            # Array indexing is O(1) but conversion to tuple is linear O(n)
            row = tuple(row)
            row_counts[row] += 1
        # For each row, check if it exists in the rows hash map
        num_equal_pairs = 0
        for column in matrix.T:
            # Again, O(n)
            column = tuple(column)
            # If the column matches with any rows, increment the answer by the number of matching rows
            if column in row_counts:
                num_equal_pairs += row_counts[column]

        return num_equal_pairs

    @staticmethod
    def builtin(grid: List[List[int]]) -> int:
        if len(grid) == 1:
            return 1
        # Count the occurrences of each row array
        row_counts = defaultdict(int)
        for row in grid:
            row = tuple(row)
            row_counts[row] += 1
        # Count the occurrences of each column array
        column_counts = defaultdict(int)
        for j in range(len(grid[0])):
            column = tuple(row[j] for row in grid)
            column_counts[column] += 1
        num_equal_pairs = 0
        for column in column_counts:
            num_equal_pairs += column_counts[column] * row_counts[column]

        return num_equal_pairs


def main() -> int:
    for grid in [
        [[3, 2, 1], [1, 7, 6], [2, 7, 7]],
        [[3, 1, 2, 2], [1, 4, 4, 5], [2, 4, 2, 2], [2, 4, 2, 2]],
        [[1]],
    ]:
        num_equal_pairs_numpy = EqualPairs.numpy(grid)
        num_equal_pairs_builtin = EqualPairs.builtin(grid)
        assert num_equal_pairs_numpy == num_equal_pairs_builtin
        print(f"Given the input {grid}, there are {num_equal_pairs_numpy} equal pairs (r_i, c_i)")

    return 0


if __name__ == "__main__":
    main()
