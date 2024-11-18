from collections import deque
from typing import Deque, List, MutableSequence


def max_sliding_window(nums: MutableSequence[int], k: int) -> List[int]:
    """
    Given an array of integers `nums` and a sliding window of size `k`, this function
    processes the array by sliding the window from the left to the right. At each position,
    the window contains `k` consecutive elements from `nums`.

    Parameters
    ----------
    nums : MutableSequence[int]
        A mutable sequence of integers
    k : int
        The size of the sliding window

    Returns
    -------
    List[int]
        A list of integers where each element is the maximum value of the corresponding sliding window of size `k`
    """
    if len(nums) == 1:
        return list(nums)

    num_deque: Deque[int] = deque()
    output: List[int] = []
    for i in range(len(nums)):
        # As long as the deque is non-empty and the element pointed to by the index at back of the deque is less than the element pointed to by the current index
        while num_deque and nums[num_deque[-1]] < nums[i]:
            # Pop the last index of the deque to maintain the monotonic non-increasing property of the deque
            num_deque.pop()
        # Push the current index to the deque as long as the element it points to is smaller than the element pointed to by the back of the deque or if the deque is empty
        num_deque.append(i)
        # Start updating the output array once we have reached the (k - 1)th index
        if i >= k - 1:
            # Check if the front and back of the deque are k elements apart
            if num_deque[-1] - num_deque[0] == k:
                # If so, pop the front of the deque to maintain the window size
                num_deque.popleft()
            # Update output with the maximum of the current window, i.e., the element pointed to by the first index of the monotonic non-increasing deque
            output.append(nums[num_deque[0]])

    return output


def main() -> int:
    data = [([1, 3, -1, -3, 5, 3, 6, 7], 3), ([2, 12, 17, 27, 77, 7, 72], 2), ([12], 1)]
    for nums, k in data:
        output = max_sliding_window(nums, k)
        print(f"Input = {nums} & k = {k} | Max sliding window = {output}")

    return 0


if __name__ == "__main__":
    main()
