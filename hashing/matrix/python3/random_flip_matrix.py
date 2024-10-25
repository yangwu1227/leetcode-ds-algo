from random import randint
from typing import Dict, List


class RandomFlip(object):
    """
    Given a `m x n` binary grid matrix with all the values set 0 initially. 
    Design an algorithm to randomly pick an index `(i, j)` where `matrix[i][j] 
    == 0` and flips it to 1. All the indices `(i, j)` where `matrix[i][j] == 0`
    should be equally likely to be returned.

    Parameters
    ----------
    m : int
        Number of rows in the matrix
    n : int
        Number of columns in the matrix

    Attributes
    ----------
    m : int
        Number of rows in the matrix
    n : int
        Number of columns in the matrix
    total : int
        Total number of indices in the matrix, which is always `m x n`
    available_indices : int
        Total number of indices that can be flipped, initially set to `m x n` and decreases by 1 after each flip
    flipped_indices : Dict[int, int]
        Dictionary to store the mapping of the indices that have been flipped before to the last available index after each flip

    Returns
    -------
    List[int]
        Returns the index `(i, j)` that needs to be flipped to 1
    """
    def __init__(self, m: int, n : int) -> None:
        """
        Initialize the `RandomFlip` class with the given `m x n` matrix.

        Parameters
        ----------
        m : int
            Number of rows in the matrix
        n : int
            Number of columns in the matrix
        """
        self.m: int = m
        self.n: int = n
        self.total: int = m * n
        self.available_indices: int = self.total
        self.flipped_indices: Dict[int, int] = {}

    def flip(self) -> List[int]:
        """
        Randomly pick an index `(i, j)` where `matrix[i][j] == 0` and flips it to 1.

        Returns
        -------
        List[int]
            The index `(i, j)` that needs to be flipped to 1
        """
        if self.available_indices == 0:
            return []

        # Random index from 0, ... self.available_indices
        random_index = randint(a=0, b=self.available_indices - 1)
        self.available_indices -= 1

        # If 'random_index' has already been flipped before, return the last available index instead
        # If 'random_index' is not an existing key, get simply returns 'random_index' as index to flip
        index_to_flip = self.flipped_indices.get(random_index, random_index)

        # The current 'random_index' should not be chosen again, so map it to the last available index
        # If the next 'random_index' is the same, then 'index_to_flip' would be the last available index instead
        self.flipped_indices[random_index] = self.flipped_indices.get(self.available_indices, self.available_indices)

        # Convert from single 'index_to_flip' to [i, j]
        return [index_to_flip // self.n, index_to_flip % self.n]

    def reset(self) -> None:
        """
        Resets the matrix to its initial state, where all the values are set to 0.

        Returns
        -------
        None
        """
        self.flipped_indices.clear()
        self.available_indices = self.total

def main() -> int:

    test_cases = [
        ((3, 1), ["flip", "flip", "flip", "flip", "reset", "flip"]),
        ((2, 4), ["flip", "flip", "flip", "flip", "flip", "reset", "flip"])
    ]

    for (m, n), actions in test_cases:

        random_flip = RandomFlip(m=m, n=n)
        print(f"Matrix has shape: ({m}, {n})")
        for action in actions:
            print(f"Action is - {action}")
            if action == "flip":
                print(random_flip.flip())
                print(f"Total available indices = {random_flip.available_indices}")
            elif action == "reset":
                print(f"Resetting")
                random_flip.reset()
                print(f"Total available indices = {random_flip.available_indices}")
        print('\n')
    return 0

if __name__ == "__main__":

    main()
