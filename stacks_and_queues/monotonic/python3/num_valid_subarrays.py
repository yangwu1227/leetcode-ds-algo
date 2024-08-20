from array import array
from typing import MutableSequence, List

def num_valid_subarrays(nums: MutableSequence[int]) -> int:
    """
    Returns the number of non-empty subarrays where the leftmost element is not larger than any other elements in the subarray.

    Parameters
    ----------
    nums : MutableSequence[int]
        A mutable sequence of integers representing the input array

    Returns
    -------
    int
        The total number of valid subarrays
    """
    n = len(nums)
    if n == 1:
        return 1
    monotonic_increasing: MutableSequence[int] = array('I')
    # Initialize with 'n' to indicate no smaller element to the right, simplifying subarray count calculation
    next_smaller: List[int] = [n] * n
    for i in range(n):
        print(f"Processing index nums[{i}] = {nums[i]}")
        # While stack is not empty and the current element is smaller than the element at the index stored at the top of the stack
        print("Stack is empty") if not monotonic_increasing else print(f"Stack is non-empty and (top of the stack: {nums[monotonic_increasing[-1]]}) > (current element: {nums[i]})? {nums[monotonic_increasing[-1]] > nums[i]}")
        while monotonic_increasing and nums[monotonic_increasing[-1]] > nums[i]:
            print(f"Popping index {monotonic_increasing[-1]} since (top of the stack: {nums[monotonic_increasing[-1]]}) > (current element: {nums[i]})")
            print(f"Setting next_smaller[{monotonic_increasing[-1]}] = {i}")
            # Pop the stack and update the next_smaller index for that element to the current index
            next_smaller[monotonic_increasing.pop()] = i 
        monotonic_increasing.append(i)
        print(f"Stack - Indices: {monotonic_increasing} - Elements: {[nums[i] for i in monotonic_increasing]}")
        print(f"Next smaller index array - {next_smaller}")
    # The number of valid subarrays that start with nums[i] is the distance to the next smaller element
    return sum(next_smaller_index - i for i, next_smaller_index in enumerate(next_smaller))

def main() -> int:

    data = [[1, 4, 2, 5, 3], [8, 7, 4, 3, 1], [2, 2, 2], [1, 7, 9, 12]]
    for nums in data:
        num_valid = num_valid_subarrays(nums)
        print(f"Given nums = {nums}, there are {num_valid} valid subarays\n")

    return 0

if __name__ == "__main__":

    main()
