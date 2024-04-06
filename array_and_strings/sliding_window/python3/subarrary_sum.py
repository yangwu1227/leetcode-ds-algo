from typing import List

def find_best_subarray(nums: List[int], k: int) -> int:
    """ 
    Given an integer array nums and an integer k, find the sum of the subarray with the largest sum whose length is k.
    
    Parameters
    ----------
    nums : List[int]
        A list of integers
    k : int
        An integer
        
    Returns
    -------
    int
        The sum of the subarray with the largest sum whose length is k.
    """
    curr_sum = 0
    
    # First window start from index 0 to index k - 1
    for i in range(k):
        # Add the next element to the current sum
        curr_sum += nums[i]
    # After the first window, the sum of all its elements is the first answer
    ans = curr_sum
    # Slide the window towards the right
    for i in range(k, len(nums)):
        # Add the next element to the window
        curr_sum += nums[i]
        # Remove the i - k element to keep the window size k
        curr_sum -= nums[i - k]
        # Integers in python are immutable and so 'ans' has not changed
        # If the curr_sum is larger than the answer (i.e. sum of the previous window), update
        ans = max(ans, curr_sum)
            
    return ans

def main() -> int:
    
    nums = [3, -1, 4, 12, -8, 5, 6]
    k = 4
    
    result = find_best_subarray(nums, k)
    
    print(f"Given input {nums} and k = {k}, the largest sum of the a k-subarray is {result}")
    
    return 0

if __name__ == "__main__":
    
    main()
