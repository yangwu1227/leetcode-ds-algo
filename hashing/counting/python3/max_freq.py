from collections import Counter
from collections.abc import Sequence


def max_freq(nums: Sequence[int]) -> int:
    """
    Given an array `nums` consisting of positive integers, return the total count of the elements in `nums` that appear with the highest frequency.

    Parameters
    ----------
    nums : Sequence[int]
        A sequence of positive integers

    Returns
    -------
    int
        Total count of all elements with the highest frequency
    """
    if len(nums) == 1:
        return 1

    # O(n) to build
    counts = Counter(nums)

    # Find highest count cost O(n)
    highest_count = max(counts.values())

    # O(n) at worst if all counts are the same
    total_count = sum(count for count in counts.values() if count == highest_count)

    return total_count


def main() -> int:
    for nums in [[1, 2, 2, 3, 1, 4], (10, 12, 11, 9, 6, 19, 11)]:
        max_count = max_freq(nums)
        print(
            f"Given the input {nums}, the total count of elements that appear with the highest frequency is {max_count}"
        )

    return 0


if __name__ == "__main__":
    main()
