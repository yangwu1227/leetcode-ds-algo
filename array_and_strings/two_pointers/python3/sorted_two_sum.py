from typing import List

def check_for_target(nums: List[int], target: int) -> bool:
    """
    Given a sorted array of unique integers and a target integer, return true if there exists a pair of numbers 
    that sum to target, false otherwise. 

    Parameters
    ----------
    nums : List[int]
        Input array of sorted (ascending) integers.
    target : int
        Target integer.

    Returns
    -------
    bool
        True if there is a pair of numbers that sum to target, False if there is none.
    """
    left_index = 0
    right_index = len(nums) - 1
    
    while left_index < right_index:
        
        # X + Y
        current_sum = nums[left_index] + nums[right_index]
        
        if (current_sum == target):
            return True
        
        if (current_sum > target):
            # Decrease the Y since we are over the target
            right_index -= 1
        elif (current_sum < target):
            # Increase the X since we are under the target
            left_index += 1
    
    # If the while loop finished, then there is no pair that sums to target
    return False

def main() -> int:
    
    nums_1 = [1, 2, 4, 6, 8, 9, 14, 15]
    nums_2 = [2, 9, 23, 89]
    
    target_1 = 13
    target_2 = 39
    
    for nums, target in zip([nums_1, nums_2], [target_1, target_2]):
        
        sum_to_target = check_for_target(nums, target)
        
        print(f"The input {nums} sums to target {target}:", sum_to_target)
        
    return 0
    
if __name__ == "__main__":
    
    main()
