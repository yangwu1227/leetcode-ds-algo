from collections.abc import Sequence 
from collections import defaultdict
from random import randint

def binary_subarray_sum(nums: Sequence[int], k: int) -> int:
    """
    Given a binary array `nums` and an integer `k`, return the number of non-empty subarrays with a sum `k`.

    Parameters
    ----------
    nums : Sequence[int]
        A sequence of 1's or 0's
    k : int
        A positive sum constraint

    Returns
    -------
    int
        Number of subarrays with a sum equal to `k`
    """
    counts = defaultdict(int)
    # Start with empty array with a prefix sum of 0, increment its count
    counts[0] = 1
    subarray_with_sum_k_count = current_sum = 0
    # O(n) operation
    for num in nums:
        current_sum += num
        # We have seen `counts[current_sum - k]` more subarrays with sum = k since the last time the sum `current_sum - k` was seen
        # Add it to the running total count of valid subarrays seen so far
        subarray_with_sum_k_count += counts[current_sum - k]
        counts[current_sum] += 1
    
    return subarray_with_sum_k_count
        
def main() -> int:
    
    for _ in range(5):
        size = randint(2, 10)
        goal = randint(0, size)
        nums = tuple(randint(0, 1) for _ in range(size))
        num_subarrays = binary_subarray_sum(nums, goal)
        print(f"Given the array {nums}, there are {num_subarrays} with sum = {goal}")
    
    return 0
    
if __name__ == "__main__":
    
    main()
