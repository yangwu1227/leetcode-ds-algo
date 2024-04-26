from functools import reduce
from collections.abc import Sequence

class MissingNumber(object):
    """
    Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array.

    Parameters
    ----------
    nums : Sequence[int]
        A sequence of `n` numbers 

    Returns
    -------
    int
        The missing number in the range `[0, n]`
    """
    @staticmethod
    def set_approach(nums: Sequence[int]) -> int:
        # Conversion cost O(n)
        nums_set = set(nums)
        # O(n) time
        for i in range(len(nums)):
            if not i in nums_set:
                return i
        # Will never get here if `nums` is guaranteed a solution
        return -1
    
    @staticmethod
    def summation_approach(nums: Sequence[int]) -> int:
        n = len(nums)
        # Using summation
        expected_sum = n * (n + 1) // 2
        # O(n) time
        actual_sum = sum(nums)
        return expected_sum - actual_sum
    
    @staticmethod
    def xor_reduce_approach(nums: Sequence[int]) -> int:
        n = len(nums)
        return reduce(lambda x, y: x ^ y, nums + list(range(n + 1)))
    
def main() -> int:
    nums = [9, 6, 4, 2, 3, 5, 7, 0, 1]
    missing_number_set = MissingNumber.set_approach(nums)
    missing_number_summation = MissingNumber.summation_approach(nums)
    missing_number_xor_reduce = MissingNumber.xor_reduce_approach(nums)
    assert missing_number_set == missing_number_summation and missing_number_xor_reduce == missing_number_set
    print(f"Given the input {nums}, the missing number is {missing_number_summation}")
    return 0

if __name__ == "__main__":
    
    main()
