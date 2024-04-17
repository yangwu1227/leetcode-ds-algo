from typing import List

def find_average(nums: List[int], k: int) -> List[int]:
    """
    The k-radius average for a subarray of `nums` centered at index `i` with the radius `k` is the average of all elements in `nums` between the 
    indices `i - k` and `i + k` (inclusive). If there are less than `k` elements before or after the index `i`, then the k-radius average is `-1`.
    Build and return an array `avgs` of length `n` where `avgs[i]` is the k-radius average for the subarray centered at index `i`.

    Parameters
    ----------
    nums : List[int]
        A list of integers
    k : int
        A non-negative integer

    Returns
    -------
    List[int]
        The list of k-radius averages for the subarrays centered at each index of `nums`
    """
    window_size = 2 * k + 1
    # Prefill with -1 costing O(n)
    avg = [-1] * len(nums)
    
    # In this case, no element has k elements before or after it
    if (window_size > len(nums)):
        return avg
    # If radius is 0, the k-radius average for each element is simply itself
    if (k == 0):
        return nums
    
    # Find first window sum costing O(window_size)
    current_window_sum = sum(nums[slice(0, window_size)])
    # The first index with enough elements before it is k, and the first average is associated with that element
    avg[k] = current_window_sum // window_size
    
    # Only iterate through elements that have k elements before or after it
    for i in range(k + 1, len(nums) - k):
        # Current window bounds
        left = i - k 
        right = i + k
        # Slide the window by adding the next element 'nums[right]'
        # Keep window fixed by removing the leftmost element (i.e. nums[left - 1])
        current_window_sum += (nums[right] - nums[left - 1])
        avg[i] = current_window_sum // window_size
            
    return avg
    
def main() -> int:
    
    nums = [7, 4, 3, 9, 1, 8, 5, 2, 6]
    k = 3
    avg = find_average(nums, k)
    print(f"Give the input {nums} and k = {k}, the k-radius average is {avg}")
    
    return 0

if __name__ == "__main__":
    
    main()
