from typing import List, Set

import numpy as np


class SetZeros(object):
    """
    Given an `m x n` integer `matrix`, if an element is 0, set its entire row and column to 0's.

    Parameters
    ----------
    matrix : Union[List[List[int]], np.ndarray]
        A 2D matrix
    """

    @staticmethod
    def set_approach(matrix: List[List[int]]) -> None:
        rows_to_zero: Set[int] = set()
        cols_to_zero: Set[int] = set()
        m, n = len(matrix), len(matrix[0])
        # First pass to find all rows and columns that need to be zeroed 0(m x n)
        for row in range(m):
            for col in range(n):
                if matrix[row][col] == 0:
                    rows_to_zero.add(row)
                    cols_to_zero.add(col)
        # Second pass to set elements to zeros 0(m x n)
        for row in range(m):
            for col in range(n):
                if row in rows_to_zero or col in cols_to_zero:
                    matrix[row][col] = 0
        return None

    @staticmethod
    def numpy_approach(matrix: np.ndarray) -> None:
        # Find all zero elements, retruning (N, matrix.ndim) where N is the number of non-zero items
        zero_elements = np.argwhere(matrix == 0)
        # If no zero elements, do nothing
        if zero_elements.size == 0:
            return None
        # Determine the rows and columns to be zeroed
        rows_to_zero = np.unique(zero_elements[:, 0])
        cols_to_zero = np.unique(zero_elements[:, 1])
        # Zero out the rows and cols
        matrix[rows_to_zero, :] = 0
        matrix[:, cols_to_zero] = 0
        return None


def main() -> int:
    test_matrices = [
        [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]],
        [[1, 1, 1], [1, 0, 1], [1, 1, 1]],
        [[0, 2, 7, 12], [4, 2, 0, 9], [5, 0, 2, 1]],
    ]

    for matrix_list in test_matrices:
        matrix = np.array(matrix_list)
        print(f"Matrix before setting elements to zero: \n{matrix}")
        SetZeros.numpy_approach(matrix)
        print(f"Matrix after setting elements to zero: \n {matrix}\n")

    return 0


if __name__ == "__main__":
    main()
