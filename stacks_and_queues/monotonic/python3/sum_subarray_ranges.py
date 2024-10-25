from array import array
from typing import MutableSequence


def sum_subarray_ranges(nums: MutableSequence[int]) -> int:
    """
    Calculate the sum of all subarray ranges for the given array of integers.

    A subarray range is defined as the difference between the maximum and 
    minimum elements in that subarray. This function computes the sum of 
    all possible subarray ranges.

    Parameters
    ----------
    nums : MutableSequence[int]
        A mutable sequence of integers for which the subarray ranges are to be calculated

    Returns
    -------
    int
        The sum of all subarray ranges
    """
    n = len(nums)

    if n == 1:
        return 0

    output = 0
    print(f"Initialized output to {output}")
    monotonic_increasing: MutableSequence[int] = array('I')
    print(f"For each nums[i], compute its minimum span and subtract it from the output")
    for right_span_index in range(n + 1):
        print(f"  Processing index {right_span_index}, which is {nums[right_span_index] if right_span_index < n else 'end of array'}")
        print(f"  Stack is non-empty? {bool(monotonic_increasing)} and (right_span_index == n? {right_span_index == n} or {nums[monotonic_increasing[-1]] if monotonic_increasing else 'N/A'} >= {nums[right_span_index] if right_span_index < n else 'end of array'}? {nums[monotonic_increasing[-1]] >= nums[right_span_index] if monotonic_increasing and right_span_index < n else 'N/A'})")
        while monotonic_increasing and (right_span_index == n or nums[monotonic_increasing[-1]] >= nums[right_span_index]):
            top_stack_i = monotonic_increasing.pop(-1)
            print(f"    Popping index {top_stack_i}, which corresponds to {nums[top_stack_i]}")
            left_span_index = monotonic_increasing[-1] if monotonic_increasing else -1
            print(f"    The span of {nums[top_stack_i]} starts at {monotonic_increasing[-1] if monotonic_increasing else -1}") if monotonic_increasing else print(f"    Stack is empty so span of {nums[top_stack_i]} starts at -1")
            print(f"    output -= {nums[top_stack_i]} * ({top_stack_i} - {left_span_index}) * ({right_span_index} - {top_stack_i})")
            output -= nums[top_stack_i] * (top_stack_i - left_span_index) * (right_span_index - top_stack_i)
            print(f"    Updated output = {output}")
        monotonic_increasing.append(right_span_index)
        print(f"  State of the stack after processing index {right_span_index} = {monotonic_increasing}")    

    monotonic_decreasing: MutableSequence[int] = array('I')   
    print(f"\nFor each nums[i], compute its maximum span and add it to the output")
    for right_span_index in range(n + 1):
        print(f"  Processing index {right_span_index}, which is {nums[right_span_index] if right_span_index < n else 'end of array'}")
        print(f"  Stack is non-empty? {bool(monotonic_decreasing)} and (right_span_index == n? {right_span_index == n} or {nums[monotonic_decreasing[-1]] if monotonic_decreasing else 'N/A'} <= {nums[right_span_index] if right_span_index < n else 'N/A'}? {nums[monotonic_decreasing[-1]] <= nums[right_span_index] if monotonic_decreasing and right_span_index < n else 'N/A'})")
        while monotonic_decreasing and (right_span_index == n or nums[monotonic_decreasing[-1]] <= nums[right_span_index]):
            top_stack_i = monotonic_decreasing.pop(-1)
            print(f"    Popping index {top_stack_i}, which corresponds to {nums[top_stack_i]}")
            left_span_index = monotonic_decreasing[-1] if monotonic_decreasing else -1
            print(f"    The span of {nums[top_stack_i]} starts at {monotonic_decreasing[-1] if monotonic_decreasing else -1}") if monotonic_decreasing else print(f"    Stack is empty so span of {nums[top_stack_i]} starts at -1")
            print(f"    output += {nums[top_stack_i]} * ({top_stack_i} - {left_span_index}) * ({right_span_index} - {top_stack_i})")
            output += nums[top_stack_i] * (top_stack_i - left_span_index) * (right_span_index - top_stack_i)
            print(f"    Updated output = {output}")
        monotonic_decreasing.append(right_span_index)
        print(f"  State of the stack after processing index {right_span_index} = {monotonic_decreasing}")

    return output

def main() -> int:

    data = [[4, -2, -3, 4, 1], [1, 3, 3], [1, 2, 3]]
    for nums in data:
        sum_ranges = sum_subarray_ranges(nums)
        print(f"Given nums = {nums}, nums of all subarray ranges is {sum_ranges} {'-' * 40}\n")

    return 0

if __name__ == "__main__":

    main()
