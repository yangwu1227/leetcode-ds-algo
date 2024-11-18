from collections import Counter
from collections.abc import Sequence


def sum_unique(nums: Sequence[int]) -> int:
    """
    Given an integer array `nums`, return the sum of all the unique elements of `nums`.

    Parameters
    ----------
    nums : Sequence[int]
        A sequence of integers

    Returns
    -------
    int
        Sum of all unique elements
    """
    if len(nums) == 1:
        return nums[0]

    if len(nums) == 2:
        return 0 if nums[0] == nums[1] else sum(nums)

    # O(n) to build
    counts = Counter(nums)

    # O(n) to check and add to sum
    return sum(num for num, count in counts.items() if count == 1)


def main() -> int:
    for nums in [
        [1, 2, 3, 2],
        [1, 1, 1, 1, 1],
        [1, 2, 3, 4, 5],
        [2, 7, 3, 9, 7, 8, 9, 4, 6, 5],
    ]:
        unique_sum = sum_unique(nums)
        print(f"Given the input {nums}, the sum of all unique elements is {unique_sum}")

    return 0


if __name__ == "__main__":
    main()
