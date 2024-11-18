from typing import List


def find_length(nums: List[int], k: int) -> int:
    """
    Given an array of positive integers nums and an integer k, find the length of the longest subarray whose sum is less than or equal to k.

    Parameters
    ----------
    nums : List[int]
        List of positive integers
    k : int
        Integer value

    Returns
    -------
    int
        Length of the longest subarray whose sum is less than or equal to k
    """
    left = curr_sum = window_len = 0
    for right in range(len(nums)):
        # Add the next element to the current sum as we move right index forward
        curr_sum += nums[right]

        # Check if the current window (represented by left and right indices) is invalid
        # The constraint metric is 'curr_sum' and numeric restriction is 'k'
        if curr_sum > k:
            # The current window is invalid since it sums to > k, remove the element that left points to
            curr_sum -= nums[left]
            # Increment left to slide the window towards the right
            left += 1

        # Before the current iteration ends, update the length of the window
        # We add one because we need it to be left inclusive
        window_len = max(window_len, right - left + 1)

    return window_len


def main() -> int:
    k = 8
    array = [3, 1, 2, 7, 4, 2, 1, 1, 5]

    window_len = find_length(nums=array, k=k)

    print(
        f"Given {array} and constraint of <= {k}, the longest subarray has length {window_len}"
    )

    return 0


if __name__ == "__main__":
    main()
