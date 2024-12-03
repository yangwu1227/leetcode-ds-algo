from typing import Any, Dict, List, Self, Tuple, Union

import numpy as np
from scipy.sparse import random
from scipy.stats import norm


class SparseMatrix(object):
    """
    A dictionary of keys (DOK) sparse matrix class.

    Attributes
    ----------
    nrows : int
        The number of rows in the matrix
    ncols : int
        The number of columns in the matrix
    sparse_matrix : Dict[Tuple[int, int], Union[int, float]]
        A dictionary of keys sparse matrix representation
    """

    def __init__(
        self,
        nrows: int,
        ncols: int,
        sparse_matrix: Dict[Tuple[int, int], Union[int, float]],
    ) -> None:
        """
        Initializes the sparse matrix instance.

        Parameters
        ----------
        nrows : int
            The number of rows in the matrix
        ncols : int
            The number of columns in the matrix
        sparse_matrix : Dict[Tuple[int, int], Union[int, float]]
            A dictionary of keys sparse matrix representation
        """
        self.nrows = nrows
        self.ncols = ncols
        self.sparse_matrix = sparse_matrix

    def __repr__(self) -> str:
        """
        Override the `__repr__` dunder method to print readible information.

        Returns
        -------
        str
            Shape of the sparse matrix
        """
        return f"Sparse Matrix with shape ({self.nrows}, {self.ncols})"

    @staticmethod
    def to_sparse(
        dense_matrix: List[List[Union[int, float]]],
    ) -> Dict[Tuple[int, int], Union[int, float]]:
        """
        Converts a dense matrix to a sparse matrix representation.

        Parameters
        ----------
        dense_matrix : List[List[Union[int, float]]]
            The dense matrix to convert to a sparse matrix

        Returns
        -------
        Dict[Tuple[int, int], Union[int, float]]
            The sparse matrix representation of the dense matrix
        """
        sparse_matrix = {}
        for row_idx, row in enumerate(dense_matrix):
            for col_idx, cell_value in enumerate(row):
                if cell_value:
                    sparse_matrix[(row_idx, col_idx)] = cell_value
        return sparse_matrix

    def to_dense(self) -> List[List[Union[int, float]]]:
        """
        Converts the sparse matrix to a dense matrix representation.

        Returns
        -------
        List[List[Union[int, float]]]
            The dense matrix representation of the sparse matrix
        """
        dense_matrix = [[0] * self.ncols for _ in range(self.nrows)]
        for (row_idx, col_idx), cell_value in self.sparse_matrix.items():
            dense_matrix[row_idx][col_idx] = cell_value  # type: ignore
        return dense_matrix  # type: ignore

    @classmethod
    def from_dense(cls, dense_matrix: List[List[Union[int, float]]]) -> Self:
        """
        Creates a sparse matrix instance from a dense matrix.

        Parameters
        ----------
        dense_matrix : List[List[Union[int, float]]]
            The dense matrix to create the sparse matrix from

        Returns
        -------
        SparseMatrix
            The sparse matrix instance created from the dense matrix
        """
        nrows, ncols = len(dense_matrix), len(dense_matrix[0])
        sparse_matrix = cls.to_sparse(dense_matrix)
        return cls(nrows, ncols, sparse_matrix)

    @classmethod
    def from_sparse(
        cls,
        nrows: int,
        ncols: int,
        sparse_matrix: Dict[Tuple[int, int], Union[int, float]],
    ) -> Self:
        """
        Creates a sparse matrix instance from a sparse matrix representation.

        Parameters
        ----------
        nrows : int
            The number of rows in the matrix
        ncols : int
            The number of columns in the matrix
        sparse_matrix : Dict[Tuple[int, int], Union[int, float]]
            The sparse matrix representation to create the sparse matrix from

        Returns
        -------
        SparseMatrix
            The sparse matrix instance created from the sparse matrix representation
        """
        return cls(nrows, ncols, sparse_matrix)

    def __matmul__(self, other: Any) -> "SparseMatrix":
        """
        Performs matrix multiplication between two sparse matrices.

        Parameters
        ----------
        other : SparseMatrix
            The other sparse matrix to multiply with

        Returns
        -------
        SparseMatrix
            The result of the matrix multiplication
        """
        if isinstance(other, SparseMatrix):
            if self.ncols != other.nrows:
                raise ValueError(
                    "The number of columns in the left matrix must be equal to the number of rows in the right matrix"
                )

            result_sparse_matrix: Dict[Tuple[int, int], Union[int, float]] = {}
            # For each non-zero element in A[this_row_idx, common_idx]
            for (this_row_idx, common_idx), self_value in self.sparse_matrix.items():
                # For each column in B[:, other_col_idx]
                for other_col_idx in range(other.ncols):
                    # If `B[common_idx, other_col_idx]` is also non-zero, then `A[this_row_idx, common_idx]` x `B[common_idx, other_col_idx]`
                    if (common_idx, other_col_idx) in other.sparse_matrix:
                        other_value = other.sparse_matrix[(common_idx, other_col_idx)]
                        # Each C[this_row_idx, other_col_idx] entry should be `np.dot(A[this_row_idx, :], B[:, other_col_idx])`
                        result_sparse_matrix[(this_row_idx, other_col_idx)] = (
                            result_sparse_matrix.get((this_row_idx, other_col_idx), 0)
                            + self_value * other_value
                        )

            return self.from_sparse(self.nrows, other.ncols, result_sparse_matrix)
        else:
            raise NotImplementedError

    def __rmatmul__(self, other: Any) -> "SparseMatrix":
        """
        Performs matrix multiplication where the sparse matrix is on the right-hand side of the operator.

        Parameters
        ----------
        other : SparseMatrix
            The other sparse matrix to multiply with

        Returns
        -------
        SparseMatrix
            The result of the matrix multiplication
        """
        if isinstance(other, SparseMatrix):
            if other.ncols != self.nrows:
                raise ValueError(
                    "The number of columns in the left matrix must be equal to the number of rows in the right matrix"
                )
            return other.__matmul__(self)
        else:
            raise NotImplementedError


def main() -> int:
    for i in range(5):
        dtype = np.random.choice(np.array([np.float64, np.int64]), size=1)[0]
        mean = np.random.randint(0, 100, 1)[0]
        sd = np.random.randint(0, 100, 1)[0]
        rvs = norm(loc=mean, scale=sd).rvs
        nrows_a = np.random.randint(1, 100, 1)[0]
        ncols_a = np.random.randint(1, 100, 1)[0]
        nrows_b = ncols_a
        ncols_b = np.random.randint(1, 100, 1)[0]
        sparse_matrix_a = random(m=nrows_a, n=ncols_a, format="dok", dtype=dtype, data_rvs=rvs)
        sparse_matrix_b = random(m=nrows_b, n=ncols_b, format="dok", dtype=dtype, data_rvs=rvs)
        reference_output = sparse_matrix_a @ sparse_matrix_b
        reference_output = np.array(reference_output.todense())

        # Convert to list of lists
        dense_matrix_a = sparse_matrix_a.todense().tolist()
        dense_matrix_b = sparse_matrix_b.todense().tolist()
        # Instances of SparseMatrix
        sparse_matrix_a = SparseMatrix.from_dense(dense_matrix_a)
        sparse_matrix_b = SparseMatrix.from_dense(dense_matrix_b)
        output = sparse_matrix_a @ sparse_matrix_b
        output = np.array(output.to_dense(), dtype=dtype)

        print(f"Test case {i + 1}")
        print("Sparse Matrix A:")
        print(sparse_matrix_a)
        print("Sparse Matrix B:")
        print(sparse_matrix_b)

        try:
            # Compare output with reference output
            np.testing.assert_allclose(reference_output, output)
            print("The output matches the reference implementation")
        except AssertionError:
            print("The output does not match the reference implementation")
            exit(1)

        print("\n")

    return 0


if __name__ == "__main__":
    main()
