from collections.abc import Sequence

class Solution(object):
    """
    Given an array of integers `nums`, start with an initial positive value `start_value`. In each iteration,
    calculate the step by step sum of `start_value + nums[i]` for `i, ..., n`, where `n` is the length of `nums`.
    Return the minimum positive `start_value` such that each of the `n` sums is never less than 1.

    Parameters
    ----------
    nums : Sequence[int]
        A sequence of integers

    Returns
    -------
    int
        Minimum positive `start_value` that satisfies the criteria
    """
    @staticmethod
    def min_start_value_approach_one(nums: Sequence[int]) -> int:
        # Build prefix O(n)
        prefix = [nums[0]]
        for i in range(1, len(nums)):
            # Append cost O(1)
            prefix.append(prefix[-1] + nums[i])
        # O(n) operation to find the min
        min_sum = min(prefix)
        # If min_sum is less than 0, start value must be abs(min_sum) + 1
        if min_sum < 0:
            min_start_value = abs(min_sum) + 1
        # If min_sum is 0, start value can just be 1
        else:
            min_start_value = 1
        
        return min_start_value

    @staticmethod
    def min_start_value_approach_two(nums: Sequence[int]) -> int:
        min_sum = prefix_sum = 0
        # O(n) to build the prefix sum and find the minimum prefix sum in one go
        for num in nums:
            prefix_sum += num
            min_sum = min(min_sum, prefix_sum)
        # If min_sum is < 0, then max would return (1 - min_sum) to offset the negative sum
        # If min_sum is >= 0, max returns at least 1
        return max(1, 1 - min_sum)

def main() -> int:

    nums = [-3, 2, -3, 4, 2, 7, 5]
    min_start_value_approach_1 = Solution.min_start_value_approach_one(nums)
    min_start_value_approach_2 = Solution.min_start_value_approach_two(nums)
    assert min_start_value_approach_1 == min_start_value_approach_2
    print(f"Given the input {nums}, the minimum positive starting value is {min_start_value_approach_1}")
    
    return 0

if __name__ == "__main__":
    
    main()
