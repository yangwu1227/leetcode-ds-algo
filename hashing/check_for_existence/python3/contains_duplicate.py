from collections import defaultdict
from collections.abc import Sequence


def contains_duplicates(nums: Sequence[int]) -> bool:
    """
    Given an integer array `nums`, return `true` if any value appears at least twice in the array, and return `false` if every element is distinct.

    Parameters
    ----------
    nums : Sequence[int]
        A sequence of integers

    Returns
    -------
    bool
        True of there is a value that appears twice, False otherwise
    """
    num_dict: defaultdict[int, int] = defaultdict(int)
    # Cost O(n) at worse
    for num in nums:
        num_dict[num] += 1
        if num_dict[num] > 1:
            return True
    return False


def main() -> int:
    test_nums = [[1, 1, 1, 3, 3, 4, 3, 2, 4, 2], (1, 3, 9, 8, 10)]
    for nums in test_nums:
        result = contains_duplicates(nums)
        print(f"The input {nums} {'contains' if result else 'does not contain'} duplicate elements")

    return 0


if __name__ == "__main__":
    main()
