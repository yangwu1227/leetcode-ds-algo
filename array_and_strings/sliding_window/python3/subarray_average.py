from typing import List


def find_max_average(nums: List[int], k: int) -> int:
    """
    Given an integer array nums consisting of n elements, and an integer k. Find a contiguous subarray whose length is equal to k that has 
    the maximum average value and return this value.

    Parameters
    ----------
    nums : List[int]
        An integer array consisting of n elements
    k : int
        An integer representing the length of the subarray

    Returns
    -------
    int
        The maximum average value of the subarray
    """
    curr_sum = 0
    # First window 
    for i in range(k):
        curr_sum += nums[i]
    # The window size is fixed, so we can always divide by k to get the average
    ans = curr_sum / k
    # Slide the window towards the right
    for i in range(k, len(nums)):
        # Add the next element and remove the (i - k)th element to keep the window fixed
        curr_sum += nums[i] - nums[i - k]
        ans = max(ans, curr_sum / k)
    
    return ans

def main() -> int:
    
    nums = [1, 12, -5, -6, 50, 3]
    k = 4
    
    result = find_max_average(nums, k)
    
    print(f"Given the input {nums} and k = {k}, the max average of a subarray with length k is {result}")
    
    return 0

if __name__ == "__main__":
    
    main()
