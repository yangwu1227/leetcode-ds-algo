from collections import defaultdict
from collections.abc import Sequence


def max_sum(nums: Sequence[int]) -> int:
    """
    Given an array of integers `nums`, find the maximum value of `nums[i] + nums[j]`, where `nums[i]` and `nums[j]`
    have the same digit sum (the sum of their individual digits).

    Parameters
    ----------
    nums : Sequence[int]
        A sequence of positive integers

    Returns
    -------
    int
        The maximum value of `nums[i] + nums[j]`, where `nums[i]` and `nums[j]` have the same digit sum, or -1 if no such pair exists
    """
    hash_map: defaultdict[int, int] = defaultdict(int)
    ans = 0
    # O(n x k) where k is the average number of digits in an integer element
    for num in nums:
        # Compute the sum of all digits
        digit_sum = sum(int(digit) for digit in str(num))
        # If we have seen this sum before
        if digit_sum in hash_map:
            sum_of_elements = num + hash_map[digit_sum]
            # Update the answer if needed
            ans = max(ans, sum_of_elements)
        # If the current 'num' is larger than the previous 'num' with the same digit sum, update to use this current number as the new reference for future sums
        hash_map[digit_sum] = max(hash_map[digit_sum], num)
    return ans if ans else -1


def main() -> int:
    for nums in [[18, 43, 36, 13, 7], (10, 12, 19, 14)]:
        ans = max_sum(nums)
        print(
            f"Given the input {nums}, the maximum sum of equivalent pairs {f'is {ans}' if ans != -1 else 'does not exist'}"
        )

    return 0


if __name__ == "__main__":
    main()
