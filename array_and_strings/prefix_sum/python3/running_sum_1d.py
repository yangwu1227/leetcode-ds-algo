from typing import List

def running_sum(nums: List[int]) -> List[int]:
    """
    Given an array `nums`, the running sum of the array is defined as `runningSum[i] = sum(nums[0]…nums[i])`.

    Parameters
    ----------
    nums : List[int]
        A list of integers

    Returns
    -------
    List[int]
        The running sum of the array `nums`
    """
    # Modifies in-place since list is mutable
    for i in range(1, len(nums)):
        nums[i] += nums[i - 1]
        
    return nums

def main() -> int:
    
    nums = [3, 1, 2, 10, 1]
    prefix = running_sum(nums)
    print(f"Given the input {nums}, the running sum is {prefix}")
    
    return 0

if __name__ == "__main__":
    
    main()
