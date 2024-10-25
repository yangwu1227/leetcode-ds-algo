from collections import defaultdict
from typing import List

import numpy as np


class Solution(object):
    """
    Given a 2D array `nums` that contains `n` arrays of distinct integers, return a sorted array containing all the numbers that appear in all `n` arrays.

    Parameters
    ----------
    nums : List[List[int]]
        A 2D array containing `n` arrays of integers

    Returns
    -------
    List[List[int]]
        A 1D array containing the intersection of all arrays
    """
    @staticmethod
    def intersection_np(nums: List[List[int]]) -> List[List[int]]:
        # Flatten list of lists to 1d array
        array_1d = np.concatenate(nums, axis=0)
        counts = defaultdict(int)
        for val in array_1d:
            counts[val] += 1
        ans = []
        for i, val in enumerate(counts):
            if counts[val] == len(nums):
                ans.append(val)
        return sorted(ans)
    
    @staticmethod
    def intersection_set(nums: List[List[int]]) -> List[int]:
        if not nums:
            return []
        # Start with the set of the first list
        ans_set = set(nums[0])
        for array in nums[1:]:
            # Update a set with the intersection of itself and another
            ans_set.intersection_update(array)
        return sorted(ans_set)

def main() -> int:
    
    for array in ([[3, 1, 2, 4, 5], [1, 2, 3, 4], [3, 4, 5, 6]], [[1, 2, 3], [4, 5, 6]], [[7, 34, 45, 10, 12, 27, 13], [27, 21, 45, 10, 12, 13]]):
        ans_np = Solution.intersection_np(array)
        ans_set = Solution.intersection_set(array)
        assert ans_set == ans_np
        print(f"Given the input {array}, the intersection is {ans_set}")
        
    return 0
    
if __name__ == "__main__":
    
    main()
