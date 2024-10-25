from collections.abc import Sequence
from itertools import accumulate
from operator import add


class NumArray(object):
    def __init__(self, nums: Sequence[int]):
        """
        Initializer.

        Parameters
        ----------
        nums : Sequence[int]
            A sequence of integers
        """
        self.nums = nums  
        # O(n) to build the prefix sum array
        self.prefix = list(accumulate(self.nums, add))
        
    def sum_range(self, left: int, right: int) -> int:
        """
        Given an integer array `nums`, a `left` and `right` index, find the
        sum of all elements between `left` and `right` inclusive.

        Parameters
        ----------
        left : int
            An integer representing the start of the subarray
        right : int
            An integer representing the end of the subarray

        Returns
        -------
        int
            The sum of all elements in the subarray
        """
        # O(1) operation to find the subarray sum
        return self.prefix[right] - self.prefix[left] + self.nums[left]

def main() -> int:
    
    num_array = NumArray(nums=[-2, 0, 3, -5, 2, -1])
    print(f"Give the input array {num_array.nums}:")
    for left, right in zip([0, 2, 0], [2, 5, 5]):
        subarray_sum = num_array.sum_range(left, right)
        print(f"The subarray ({left}, {right}) sum = {subarray_sum}")
        
    return 0

if __name__ == "__main__":
    
    main()
