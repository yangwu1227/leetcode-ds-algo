from collections import deque
from typing import Deque, MutableSequence


def longest_subarray(nums: MutableSequence[int], limit: int) -> int:
    """
    Given an array of integers `nums` and an integer `limit`, return the size of the longest non-empty subarray such that the absolute difference between
    any two elements of this subarray is less than or equal to `limit`.

    Parameters
    ----------
    nums : MutableSequence[int]
        A mutable sequence of integers
    limit : int
        An integer limit

    Returns
    -------
    int
        The length of the longest continuous valid subarray
    """
    if len(nums) == 1:
        return 1

    monotonic_increasing: Deque[int] = deque()
    monotonic_decreasing: Deque[int] = deque()
    window_size = left = 0
    for right in range(len(nums)):
        # Keep popping until the current element is no longer breaking the monotonic increasing property
        while monotonic_increasing and monotonic_increasing[-1] > nums[right]:
            monotonic_increasing.pop()
        # Keep popping until the current element is no longer breaking the monotonic decreasing property
        while monotonic_decreasing and monotonic_decreasing[-1] < nums[right]:
            monotonic_decreasing.pop()
        # Push the elements
        monotonic_increasing.append(nums[right])
        monotonic_decreasing.append(nums[right])

        # Check if the window has become invalid, i.e., max_of_window - min_of_window > limit
        while monotonic_decreasing[0] - monotonic_increasing[0] > limit:
            # Remove the left most element of the window
            if monotonic_decreasing[0] == nums[left]:
                monotonic_decreasing.popleft()
            if monotonic_increasing[0] == nums[left]:
                monotonic_increasing.popleft()
            # Increment the left pointer now that that element has been removed from the window
            left += 1
        # Check if we have found a longer subarray
        window_size = max(window_size, right - left + 1)

    return window_size


def main() -> int:
    data = [
        ([1, 5, 6, 7, 8, 10, 6, 5, 6], 4),
        ([10, 1, 2, 4, 7, 2], 5),
        ([8, 2, 4, 7], 4),
    ]
    for nums, limit in data:
        window_size = longest_subarray(nums, limit)
        print(
            f"Given nums =  {nums} and limit = {limit}, the longest subarray that satisfies the condition has {window_size} elements"
        )

    return 0


if __name__ == "__main__":
    main()
