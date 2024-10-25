from math import inf, isinf
from typing import List


def min_subarray_len(nums: List[int], target: int) -> int:
    """
    Given an array of positive integers `nums` and a positive integer `target`, return the minimal length of a subarray whose sum is greater 
    than or equal to target. If there is no such subarray, return 0 instead.
    
    Parameters
    ----------
    nums : List[int]
        List of positive integers
    target : int
        Positive integer
        
    Returns
    -------
    int
        Minimal length of a subarray whose sum is greater than or equal to target
    """
    left = curr_sum = 0 
    window_len = inf
    for right in range(len(nums)):
        # Add elements from the right (expand window)
        curr_sum += nums[right]
        # Once we achieve window sum >= target, we can no longer do any better (i.e find a smaller valid subarray) with the left index at the current position
        # This loop stops running when window sum has become < target again
        while (curr_sum >= target):
            # Update if the current window size is smaller than the previously found window size 
            window_len = min(window_len, right - left + 1)
            # Remove the element pointed to by the left pointer and increment the left index to shrink the window
            # Shrink only after we have checked if window_len could be updated
            curr_sum -= nums[left]
            left += 1
      
    return window_len if not isinf(window_len) else 0


def main() ->  int:

    nums = [2, 3, 1, 2, 4, 3]
    target = 7
    
    result = min_subarray_len(nums, target)
    
    print(f"Given the input {nums} and target = {target}, the smallest subarray with a sum of >= {target} has length {result}")
    
    return 0

if __name__ == "__main__":
    
    main()
