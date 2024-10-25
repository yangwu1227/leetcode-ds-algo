from collections import defaultdict
from collections.abc import MutableMapping
from typing import List

import numpy as np


class MatrixPattern(object):
    """
    A class to to search for valid submatrices in a board matrix that match a pattern matrix.
    """
    def __init__(self, board: List[List[int]], pattern: List[str]) -> None:
        """
        Initialize the MatrixPattern instance with the board and pattern matrices.

        Parameters
        ----------
        board : List[List[int]]
            The board matrix to search for the pattern matrix in
        pattern : List[str]
            The pattern matrix to search for in the board matrix
        """
        self.board = board 
        self.board_nrows = len(self.board)
        self.board_ncols = len(self.board[0])
        self.pattern = pattern 
        self.pattern_nrows = len(self.pattern)
        self.pattern_ncols = len(self.pattern[0])

    def check_pattern(self, i: int, j: int) -> bool:
        """
        Check if the submatrix of the board matrix starting at the top left corner (i, j) matches the pattern matrix.

        Parameters
        ----------
        i : int
            The row index of the top left corner of the submatrix
        j : int
            The column index of the top left corner of the submatrix

        Returns
        -------
        bool
            `True` if the submatrix matches the pattern matrix, `False` otherwise
        """
        board_int_to_pattern_str: MutableMapping[int, str]  = defaultdict(str)
        pattern_str_to_board_int: MutableMapping[str, int]  = defaultdict(int)
        for pattern_row in range(self.pattern_nrows):
            for pattern_col in range(self.pattern_ncols):
                board_row, board_col = i + pattern_row, j + pattern_col
                board_int = self.board[board_row][board_col]
                pattern_str = self.pattern[pattern_row][pattern_col]
                # If this element of the pattern matrix is a digit
                if pattern_str.isdigit():
                    # Check if it matches with the element in board at the same location
                    if int(pattern_str) != board_int:
                        # If not this submatrix is invalid
                        return False
                else:
                    # Check if 'board_int' is already mapped to a 'pattern_str', and if it is not the same as the current 'pattern_str'
                    if (board_int in board_int_to_pattern_str) and (board_int_to_pattern_str[board_int] != pattern_str):
                        return False 
                    # Check if 'pattern_str' is already mapped to by a 'board_int', and if it is not the same as the current 'board_int'
                    if (pattern_str in pattern_str_to_board_int) and (pattern_str_to_board_int[pattern_str] != board_int):
                        return False 
                    # Update bidirectional maps
                    board_int_to_pattern_str[board_int] = pattern_str
                    pattern_str_to_board_int[pattern_str] = board_int
        # If we scan through every element in the submatrix without returning early, then this is a valid submatrix that matches the pattern matrix
        return True

    def find_indices(self) -> List[int]:
        """
        Find the indices of the top left corner of the submatrix in the board matrix that matches the pattern matrix.

        Returns
        -------
        List[int]
            The indices of the top left corner of the submatrix in the board matrix that matches the pattern matrix, or [-1, -1] if no such submatrix exists
        """
        # Iterate over all possible top left corners of submatrices
        for i in range(self.board_nrows - self.pattern_nrows + 1):
            for j in range(self.board_ncols - self.pattern_ncols + 1):
                if self.check_pattern(i=i, j=j):
                    return [i, j]
        return [-1, -1]
        
def main() -> int:

    test_cases = [
        (
            # Test board 1
            [[1, 2, 2],
             [2, 2, 3],
             [2, 3, 3]],
            # Test pattern matrix 1
            ["ab", "bb"]
        ),
        (
            # Test board 2
            [[1, 1, 2],
             [3, 3, 4],
             [6, 6, 6]],
            # Test pattern matrix 2
            ["ab", "66"]
        ),
        (
            # Test board 3
            [[1, 2],
             [2, 1]],
            # Test pattern matrix 3
            ["xx"]
        ),
        (
            # Test board 4 
            [[1, 2, 3, 4],
             [5, 6, 1, 2],
             [3, 4, 5, 6],
             [7, 8, 9, 1]],
            # Test pattern matrix 4
            ["12", "34"]
        ),
        (
            # Test board 5 
            [[5, 5, 5, 5, 5],
             [5, 1, 2, 3, 5],
             [5, 4, 5, 6, 5],
             [5, 7, 8, 9, 5],
             [5, 5, 5, 5, 5]],
            # Test pattern matrix 5
            ["12", "45"]
        )
    ]
    for board, pattern in test_cases:
        matrix_pattern = MatrixPattern(board=board, pattern=pattern)
        indices = matrix_pattern.find_indices()
        print(f"Board: \n {np.array(board)}")
        print(f"Pattern: \n {pattern}")
        print(f"Indices: \n {indices}")
        print('\n')

    return 0

if __name__ == "__main__":

    main()
