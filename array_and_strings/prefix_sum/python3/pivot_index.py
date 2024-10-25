from itertools import accumulate
from operator import add
from typing import List


class Solution(object):
    """
    Given an array of integers `nums`, calculate the pivot index of this array. The pivot index is the index where the sum of all the numbers 
    strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right. 
    
    If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the 
    right edge of the array.

    Parameters
    ----------
    nums : List[int]
        A list of integers

    Returns
    -------
    int
        The leftmost pivot index, or, if such index exists, -1
    """
    @staticmethod
    def pivot_index_1(nums: List[int]) -> int:
        # O(n) to build prefix sum
        prefix = list(accumulate(nums))
            
        for i in range(len(nums)):
            # Left and right sums are 0 if i is pointing at the start or end of `nums`
            # Otherwise use the formula for computing subarray sums from prefix sum array
            left_sum = 0 if i == 0 else prefix[i - 1] - prefix[0] + nums[0]
            right_sum = 0 if i == len(nums) - 1 else prefix[-1] - prefix[i + 1] + nums[i + 1] 
            if left_sum == right_sum:
                return i
        # If loop completes without returning, no pivot found
        return -1
    
    @staticmethod
    def pivot_index_2(nums: List[int]) -> int:
        # O(n) to build prefix sum
        prefix = list(accumulate(nums, add))
        # Total sum
        total_sum = prefix[-1]
        
        for i in range(len(nums)):
            # The left sum is the sum of all elements before i, if i is > 0
            left_sum = prefix[i - 1] if i > 0 else 0
            # The right sum is the difference between total sum and prefix[i]
            # Since prefix[i] is the sum of all elements up to and including i
            right_sum = total_sum - prefix[i]
            if left_sum == right_sum:
                return i
            
        return -1
        
def main() -> int:
    
    nums = [1, 7, 3, 6, 5, 6]
    pivot_1 = Solution.pivot_index_1(nums)
    pivot_2 = Solution.pivot_index_2(nums)
    assert pivot_1 == pivot_2
    print(f"Give the array {nums}, the pivot index {'does not exist' if pivot_1 == -1 else f'is {pivot_2}'}")
    
    return 0
    
if __name__ == "__main__":
    
    main()
        