from collections import defaultdict
from collections.abc import Sequence

import numpy as np


def max_subarray_unique(nums: Sequence[int]) -> int:
    """
    Given an array of positive integers `nums`, find the maximum sum among all unique subarrays.

    Parameters
    ----------
    nums : Sequence[int]
        A sequence of positive integers

    Returns
    -------
    int
        The maximum sum of the unique subarray
    """
    if len(nums) == 1:
        return nums[0]
    counts = defaultdict(int)
    left = max_sum = current_sum = 0
    # O(n) operation
    for right in range(len(nums)):
        # Add to counts hash map and update current sum
        counts[nums[right]] += 1
        current_sum += nums[right]
        # If the count of any element exceeds 1, window has become invalid
        while counts[nums[right]] > 1:
            # Decrement the count of the element pointed to by the left pointer, shrinking the window
            counts[nums[left]] -= 1
            # Subtract from nums[left] from the current window sum
            current_sum -= nums[left]
            # Slide the window rightward
            left += 1
        # See if we have found a larger sum
        max_sum = max(max_sum, current_sum)

    return max_sum


def main() -> int:
    for _ in range(5):
        size = np.random.randint(low=1, high=23)
        random_vector = np.random.randint(low=1, high=1000, size=size)
        random_probs = random_vector / np.sum(random_vector)
        nums = np.random.choice(a=range(size), size=size, p=random_probs).tolist()
        max_sum = max_subarray_unique(nums)
        print(f"Given the input {nums}, the maximum sum of a subarray is {max_sum}")

    return 0


if __name__ == "__main__":
    main()
