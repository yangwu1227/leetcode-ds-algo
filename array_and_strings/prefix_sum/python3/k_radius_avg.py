from collections.abc import Sequence
from typing import List


def find_average(nums: Sequence[int], k: int) -> List[int]:
    """
    The k-radius average for a subarray of `nums` centered at index `i` with the radius `k` is the average of all elements in `nums` between the 
    indices `i - k` and `i + k` (inclusive). If there are less than `k` elements before or after the index `i`, then the k-radius average is `-1`.
    Build and return an array `avgs` of length `n` where `avgs[i]` is the k-radius average for the subarray centered at index `i`.

    Parameters
    ----------
    nums : Sequence[int]
        A sequence of integers
    k : int
        A non-negative integer

    Returns
    -------
    List[int]
        The list of k-radius averages for the subarrays centered at each index of `nums`
    """
    # Build prefix in place, which costs O(n) time
    prefix = [nums[0]]
    for i in range(1, len(nums)):
        prefix.append(prefix[-1] + nums[i])
    
    avg = []
    window_size = 2 * k + 1
    for i in range(len(nums)):
        # Start of window, and if (i - k) < 0, return -1
        start = max(-1, i - k)
        # End of window, and if (i + k) > len(nums), return len(nums)
        end = min(len(nums), i + k)
        
        # There are less than k elements before or after index i
        if start == -1 or end == len(nums):
            avg.append(-1)
        else:
            # Find avg of subarray in O(1) time
            avg.append((prefix[end] - prefix[start] + nums[start]) // (window_size))
            
    return avg   
        
def main() -> int:
    
    nums = [7, 4, 3, 9, 1, 8, 5, 2, 6]
    k = 3
    avg = find_average(nums, 3)
    print(f"Given the input {nums} and k = {k}, the k-radius average array is {avg}")\
    
    return 0

if __name__ == "__main__":
    
    main()
