from typing import MutableSequence, List, Deque
from collections import deque

def sum_subarray_mins(x: MutableSequence) -> int:
    """
    Calculate the sum of the minimum values of all subarrays in the given sequence.

    Parameters
    ----------
    x : MutableSequence
        A mutable sequence of integers for which the sum of minimums of all subarrays is to be calculated

    Returns
    -------
    int
        The sum of the minimum values of all subarrays in the sequence, modulo 10**9 + 7
    """
    if len(x) == 1:
        return x[0]

    mod = 10**9 + 7
    n = len(x)
    # Each left[i] stores the number of contiguous subarrays ending at x[i] where x[i] is the minimum element, and the count including x[i] itself
    left_spans: List[int] = [0] * n
    # Each right[i] stores the number of contiguous subarrays starting at x[i] where x[i] is the minimum element, and the count including x[i] itself
    right_spans: List[int] = [0] * n 

    monotonic_increasing: Deque[int] = deque()
    # For each x[i], find its minimum span to its left
    for i in range(n):
        # While the stack is non-empty and the top of the stack is >= the current element
        while monotonic_increasing and x[monotonic_increasing[-1]] >= x[i]:
            # Pop to ensure that we maintain a stack of indices where the elements corresponding to those indices are strictly less than x[i] to its left
            monotonic_increasing.pop()
        # If the stack is empty, then there is just 1 continuous subarray where x[i] is the minimum, which is x[i] itself, so 0 + 1
        # Otherwise, the minimum span is calculated as the distance between i and the index of the previous smaller element at the top of the stack
        left_spans[i] = i + 1 if not monotonic_increasing else i - monotonic_increasing[-1]
        monotonic_increasing.append(i)

    monotonic_increasing.clear()
    # For each x[i], find its minimum span to its right
    for i in range(n - 1, -1, -1):
        # While the stack is non-empty and the top of the stack is > the current element
        while monotonic_increasing and x[monotonic_increasing[-1]] > x[i]:
            # Pop to ensure that we maintain a stack of indices where the elements corresponding to those indices are strictly less than x[i] to its right
            monotonic_increasing.pop()
        # If the stack is empty, there is no smaller element to the right of x[i]
        # Otherwise, the minimum span is calculated as the distance between the index of the next smaller element at the top of the stack and i
        right_spans[i] = n - i if not monotonic_increasing else monotonic_increasing[-1] - i
        monotonic_increasing.append(i)

    output = 0
    for i in range(n):
        # The contribution of x[i] as the minimum in all continuous subarrays where it is the minimum
        output = (output + x[i] * left_spans[i] * right_spans[i]) % mod

    return output

def main() -> int:

    data = [[3, 1, 2, 4], [11, 81, 94, 43, 3]]
    for array in data:
        min_sum = sum_subarray_mins(array)
        print(f"Given array = {array}, the sum of all subarray minimums is {min_sum}")

    return 0

if __name__ == "__main__":

    main()
