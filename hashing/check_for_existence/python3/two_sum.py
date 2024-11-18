from collections.abc import Sequence
from typing import List


class Solution(object):
    """
    Given an array of integers `nums` and an integer `target`, return indices of two numbers such that they add up to `target`. We cannot use
    the same index twice.

    Parameters
    ----------
    nums : Sequence[int]
        An array of integers (unsorted)
    target : int
        A positive integer

    Returns
    -------
    List[int]
        The indices of two numbers that sum up to `target`
    """

    @staticmethod
    def two_passes_two_sum(nums: Sequence[int], target: int) -> List[int]:
        # Keys are the elements and values are their respective indices, costing O(n)
        hash_map = {}
        for i, num in enumerate(nums):
            hash_map[num] = i

        # Check for the existence of `target - num`
        for j, num in enumerate(nums):
            diff = target - num
            if (diff in hash_map) and (hash_map[diff] != j):
                return sorted([hash_map[diff], j])

        # Will never get here if a solution is guaranteed for each input `nums`
        return [-1, -1]

    @staticmethod
    def one_pass_two_sum(nums: Sequence[int], target: int) -> List[int]:
        # Single pass
        hash_map = {}
        for i, num in enumerate(nums):
            diff = target - num
            if diff in hash_map:
                return sorted([hash_map[diff], i])
            # Add the current num to the hashmap after checking to avoid collision with previous keys
            hash_map[num] = i

        return [-1, -1]


def main() -> int:
    nums = [2, 7, 11, 15]
    target = 9
    result_1 = Solution.two_passes_two_sum(nums, target)
    result_2 = Solution.one_pass_two_sum(nums, target)
    assert result_1 == result_2
    print(
        f"Give the input {nums} and target = {target}, the indices of the two numbers are {result_2}"
    )

    return 0


if __name__ == "__main__":
    main()
