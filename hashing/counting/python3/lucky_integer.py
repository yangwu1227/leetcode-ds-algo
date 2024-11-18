from collections import Counter
from collections.abc import Sequence


def find_lucky_integer(nums: Sequence[int]) -> int:
    """
    A lucky integer is defined as an integer that has a count equaling its value. Given an array of integers, return the largest lucky integer in the array.

    Parameters
    ----------
    nums : Sequence[int]
        A sequence of positive integers

    Returns
    -------
    int
        Largest lucky integer or -1 if no such integer exists
    """
    # O(n) to build
    counts = Counter(nums)
    largest_lucky_integer = max(
        (num for num, count in counts.items() if num == count), default=-1
    )
    return largest_lucky_integer


def main() -> int:
    for nums in [[2, 2, 3, 4], [1, 2, 2, 3, 3, 3], [2, 2, 2, 3, 3]]:
        largest_lucky_integer = find_lucky_integer(nums)
        print(
            f"Give the input {nums}, the largest lucky integer {f'is {largest_lucky_integer}' if largest_lucky_integer != -1 else 'does not exist'}"
        )

    return 0


if __name__ == "__main__":
    main()
