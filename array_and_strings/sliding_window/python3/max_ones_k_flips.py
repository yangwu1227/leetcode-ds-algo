from typing import List

def longest_ones(nums: List[int], k: int) -> int:
    """
    Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if we can flip at most k 0's.

    Parameters
    ----------
    nums : List[int]
        A binary array of 1's and 0's
    k : int
        An integer of length

    Returns
    -------
    int
        Maximum number of consecutive 1's
    """
    curr_zero_count = left = window_len = 0
    for right in range(len(nums)):
        # Check if the next element is zero, if so, add to the counter
        if nums[right] == 0:
            curr_zero_count += 1
        # Check if the window has become invalid, i.e., > k zeros that we can no longer flip
        while curr_zero_count > k:
            # If the element the left pointer points to is 0, remove it
            if nums[left] == 0:
                curr_zero_count -= 1
            # Slide the window right
            left += 1
        
        # Check if the current window length is greater than the previous
        window_len = max(window_len, right - left + 1)
        
    return window_len
        
def main() -> int:
    
    nums_1 = [0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1]
    nums_2 = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0]
    k_1 = 3
    k_2 = 2
    
    for nums, k in zip([nums_1, nums_2], [k_1, k_2]):
        result = longest_ones(nums, k)
        print(f"Given input {nums} and k = {k}, the longest consecutive subarray of 1's has length {result}")
    
    return 0

if __name__ == "__main__":
    
    main()
