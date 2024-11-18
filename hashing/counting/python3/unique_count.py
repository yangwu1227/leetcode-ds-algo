from collections import Counter
from collections.abc import Sequence


def unique_count(nums: Sequence[int]) -> bool:
    """
    Given an array of integers, return true if all elements have unique counts.

    Parameters
    ----------
    nums : Sequence[int]
        A sequence of integers, which could be negative or positive

    Returns
    -------
    bool
        `True` if all elements have unique counts otherwise `False`
    """
    if len(nums) == 1:
        return True

    # O(n) to build
    counts = Counter(nums)

    # If all elements are unique with the same count, this would cost O(n)
    set_of_unique_counts = set(count for count in counts.values())

    return len(set_of_unique_counts) == len(counts)


def main() -> int:
    for nums in [[1, 2, 2, 1, 1, 3], [1, 2], [-3, 0, 1, -3, 1, 1, 1, -3, 10, 0]]:
        all_counts_unique = unique_count(nums)
        print(
            f"Given the input {nums}, {'all elements have unique counts' if all_counts_unique else 'not all elements have unique counts'}"
        )

    return 0


if __name__ == "__main__":
    main()
