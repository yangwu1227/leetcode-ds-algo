from collections import defaultdict
from collections.abc import Sequence


def subarray_odd(nums: Sequence[int], k: int) -> int:
    """
    Given an array of positive integers `nums` and an integer `k`, find the number of subarrays with exactly `k` odd numbers.

    Parameters
    ----------
    nums : Sequence[int]
        A sequence of integers
    k : int
        The number of odd numbers to find in the subarrays

    Returns
    -------
    int
        The number of subarrays with exactly `k` odd numbers
    """
    counts = defaultdict(int)
    counts[0] = 1
    current_odd_count = total_odd_count = 0
    # O(n)
    for num in nums:
        current_odd_count += num & 1
        total_odd_count += counts[current_odd_count - k]
        counts[current_odd_count] += 1
    return total_odd_count


def main() -> int:
    for nums, k in zip(
        [[1, 1, 2, 1, 1], [2, 2, 2, 1, 2, 2, 1, 2, 2, 2], [3, 2, 4, 5, 6, 7]], [3, 2, 2]
    ):
        ans = subarray_odd(nums, k)
        print(
            f"Give the input {nums} and k = {k}, there are {ans} subarrays with {k} odd numbers"
        )

    return 0


if __name__ == "__main__":
    main()
