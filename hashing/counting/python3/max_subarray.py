from collections import defaultdict
from collections.abc import Sequence


def max_subarray_length(nums: Sequence[int], k: int) -> int:
    """
    Given an integer array `nums` and an integer `k`, return the length of the longest valid array.

    Parameters
    ----------
    nums : Sequence[int]
        A sequence of positive integers
    k : int
        A positive constraint

    Returns
    -------
    int
        The longest subarray whose elements have counts less than or equal to `k`
    """
    # O(n) to build
    counts = defaultdict(int)
    left = window_len = 0
    for right in range(len(nums)):
        # Expand the window forward
        counts[nums[right]] += 1
        # If any count in the window exceeds k, window has become invalid
        while counts[nums[right]] > k:
            # Decrement the count of the element the left pointer points to
            counts[nums[left]] -= 1
            # Slide the window forward
            left += 1
        # Check if answer should be updated
        window_len = max(window_len, right - left + 1)

    return window_len


def main() -> int:
    test_nums = [
        [1, 2, 3, 1, 2, 3, 1, 2],
        [1, 2, 1, 2, 1, 2, 1, 2],
        (5, 5, 5, 5, 5, 5, 5),
    ]
    test_ks = (2, 1, 4)
    for nums, k in zip(test_nums, test_ks):
        max_len = max_subarray_length(nums, k)
        print(
            f"Given the input {nums}, the longest subarray whose elements have counts less than or equal to {k} is {max_len}"
        )

    return 0


if __name__ == "__main__":
    main()
