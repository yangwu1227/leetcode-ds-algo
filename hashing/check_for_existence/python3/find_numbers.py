from collections.abc import Sequence
from typing import List

def find_numbers(nums: Sequence[int]) -> List[int]:
    """
    Given an integer array `nums`, find all the unique numbers `x` in nums that satisfy the following: `x + 1` is not in `nums`, and `x - 1 `is not in `nums`.

    Parameters
    ----------
    nums : Sequence[int]
        A sequence of integers

    Returns
    -------
    List[int]
        All values `x` in `nums` that satisfies the condition
    """
    # This conversion costs O(n)
    nums_set = set(nums)
    result = []
    # Iterate through nums, costing O(n)
    for num in nums_set:
        if not ((num + 1 in nums) and (num - 1 in nums)):
            result.append(num)
    return result

def main() -> int:
    
    nums = [1, 3, 2, 9, 7, 5, 4, 8, 10]
    result = find_numbers(nums)
    print(f"Give the input {nums}, the result is {result}")
    
    return 0

if __name__ == "__main__":
    
    main()
