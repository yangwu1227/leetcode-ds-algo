from typing import Sequence
from collections import defaultdict
import numpy as np

def subarray_sum(nums: Sequence[int], k: int) -> int:
    """
    Given an integer array `nums` and an integer `k`, find the number of subarrays whose sum is equal to `k`.

    Parameters
    ----------
    nums : Sequence[int]
        A sequence of integers
    k : int
        An integer contraint

    Returns
    -------
    int
        Number of subarrays whose sum equal `k`
    """
    counts = defaultdict(int)
    # Empty subarray with sum of 0 has a count of 1
    counts[0] = 1
    subarray_with_sum_k_count = curr_sum = 0
    
    # O(n)
    for num in nums:
        # Add the next element
        curr_sum += num
        # Update the answer, which is the count of the prefix sum (curr_sum - k)
        subarray_with_sum_k_count += counts[curr_sum - k]
        # Keep track of the count of each prefix sum
        counts[curr_sum] += 1
        
    return subarray_with_sum_k_count

def main() -> int:
    
    for _ in range(5):
        k = np.random.randint(low=0, high=10)
        nums_size = np.random.randint(low=1, high=20)
        nums = np.random.randint(low=0, high=10, size=(nums_size, )).tolist()
        ans = subarray_sum(nums, k)
        print(f"Give the input {nums}, the number of subarrays whose sum is {k} is {ans}")
    
    return 0

if __name__ == "__main__":
    
    main()
