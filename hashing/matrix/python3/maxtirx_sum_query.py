from typing import List, Set

import numpy as np
from scipy.sparse import lil_matrix


class MatrixSumQueries(object):
    """
    Given an integer `n` and a 0-indexed 2D array queries where `queries[i] =
    [type_i, index_i, val_i]`. Initially, all values of the `n x n` matrix are
    initialized to 0's. For each query:

        * If `type_i == 0`, set the values in the row with `index_i` to `val_i`, overwriting any previous values
        * If `type_i == 1`, set the values in the column with `index_i` to `val_i`, overwriting any previous values

    Then, return the sum of the matrix after all queries are applied.

    Parameters
    ----------
    n: int
        The size of the matrix
    queries: List[List[int]]
        A 0-indexed 2D array where `queries[i] = [type_i, index_i, val_i]`

    Returns
    -------
    int
        The sum of the matrix after all queries are applied
    """

    @staticmethod
    def scipy_approach(n: int, queries: List[List[int]]) -> int:
        matrix = lil_matrix((n, n), dtype=np.int32)
        for type_col, index, val in queries:
            if type_col:
                matrix[:, index] = val
            else:
                matrix[index, :] = val
        return int(matrix.sum(dtype=np.int32))

    @staticmethod
    def effcient_approach(n: int, queries: List[List[int]]) -> int:
        matrix_sum = 0
        visited_columns: Set[int] = set()
        visited_rows: Set[int] = set()
        vertical_cells_left_to_modify, horizontal_cells_left_to_modify = n, n
        # Start from the last query and move forward
        for type_col, index, val in queries[::-1]:
            # If we have not visited the col and type == 1
            if type_col and (index not in visited_columns):
                # Add all cells in this column that we still can modify to 'val'
                matrix_sum += val * vertical_cells_left_to_modify
                # Decrement the numbers of cells horizontally that we can modify in the next query
                horizontal_cells_left_to_modify -= 1
                visited_columns.add(index)
            elif (not type_col) and (index not in visited_rows):
                # Add all cells in this row that we still can modify to 'val'
                matrix_sum += val * horizontal_cells_left_to_modify
                # Decrement the nubmers of cells vertically that we can modify
                vertical_cells_left_to_modify -= 1
                visited_rows.add(index)
        return matrix_sum


def main() -> int:
    test_cases = [
        (3, [[0, 0, 4], [0, 1, 2], [1, 0, 1], [0, 2, 3], [1, 2, 1]]),
        (3, [[0, 0, 1], [1, 2, 3], [1, 2, 2], [0, 2, 3], [1, 0, 4]]),
        (
            10**5,
            [[0, 8000, 4], [1, 10**2, 12], [1, 3435, 27], [0, 4, 77], [0, 7**2, 17]],
        ),
    ]
    for n, queries in test_cases:
        matrix_sum_efficient = MatrixSumQueries.effcient_approach(n=n, queries=queries)
        matrix_sum_scipy = MatrixSumQueries.scipy_approach(n=n, queries=queries)
        assert matrix_sum_efficient == matrix_sum_scipy
        print(
            f"Given n = {n} and queries = {queries}, the matrix sum is {matrix_sum_scipy}"
        )

    return 0


if __name__ == "__main__":
    main()
