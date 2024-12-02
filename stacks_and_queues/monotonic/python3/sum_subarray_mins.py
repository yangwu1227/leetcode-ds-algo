from collections import deque
from typing import Deque, List, MutableSequence


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
    print(f"Left minimum span calculations {'-' * 40}")
    for i in range(n):
        print(f"  Processing element {x[i]} at index {i}")
        # While the stack is non-empty and the top of the stack is >= the current element
        while monotonic_increasing and x[monotonic_increasing[-1]] >= x[i]:
            print(
                f"  Popping index {monotonic_increasing[-1]} (value: {x[monotonic_increasing[-1]]}) because it's >= {x[i]}"
            )
            monotonic_increasing.pop()
        # If the stack is empty, then there is just 1 continuous subarray where x[i] is the minimum, which is x[i] itself, so 0 + 1
        # Otherwise, the minimum span is calculated as the distance between i and the index of the previous smaller element at the top of the stack
        left_spans[i] = i + 1 if not monotonic_increasing else i - monotonic_increasing[-1]
        monotonic_increasing.append(i)
        print(f"  Updated left_spans[{i}] = {left_spans[i]}")
        print(f"  Stack after processing {x[i]}: {list(monotonic_increasing)}")

    monotonic_increasing.clear()
    print(f"Right minimum span calculations {'-' * 40}")
    for i in range(n - 1, -1, -1):
        print(f"  Processing element {x[i]} at index {i}")
        # While the stack is non-empty and the top of the stack is > the current element
        while monotonic_increasing and x[monotonic_increasing[-1]] > x[i]:
            print(
                f"  Popping index {monotonic_increasing[-1]} (value: {x[monotonic_increasing[-1]]}) because it's > {x[i]}"
            )
            monotonic_increasing.pop()
        # If the stack is empty, there is no smaller element to the right of x[i]
        # Otherwise, the minimum span is calculated as the distance between the index of the next smaller element at the top of the stack and i
        right_spans[i] = n - i if not monotonic_increasing else monotonic_increasing[-1] - i
        monotonic_increasing.append(i)
        print(f"  Updated right_spans[{i}] = {right_spans[i]}")
        print(f"  Stack after processing {x[i]}: {list(monotonic_increasing)}")

    output = 0
    print(f"Final output computations {'-' * 40}")
    for i in range(n):
        # The contribution of x[i] as the minimum in all continuous subarrays where it is the minimum
        output = (output + x[i] * left_spans[i] * right_spans[i]) % mod
        print(
            f"  Contribution of element {x[i]} at index {i}: {x[i]} * {left_spans[i]} * {right_spans[i]}"
        )
        print(f"  Updated output: {output}")

    return output


def main() -> int:
    data = [[3, 1, 2, 4], [11, 81, 94, 43, 3]]
    for array in data:
        min_sum = sum_subarray_mins(array)
        print(f"Given array = {array}, the sum of all subarray minimums is {min_sum}\n")

    return 0


if __name__ == "__main__":
    main()
