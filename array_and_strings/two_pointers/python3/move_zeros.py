from typing import List


class Solution(object):
    """
    Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
    Note that you must do this in-place without making a copy of the array.

    Parameters
    ----------
    nums : List[int]
        Input integer array.
        
    Return
    ------
    None
        In-place operation on list.
    """
    @staticmethod
    def move_zeros_1(nums: List[int]) -> None:
        # Single element array of zero
        if len(nums) == 1 and nums[0] == 0:
            return nums
        
        left_index = 0
        right_index = len(nums) - 1
        
        for i in range(len(nums)):
            
            left_el = nums[left_index]
            right_el = nums[right_index]
            
            if left_el == 0:
                # If zero, move to end of array
                nums.append(nums.pop(left_index))
                # Found a zero at the start, decrement the right index since we appended a zero at the end (shifted towards the left)
                right_index -= 1
            elif right_el == 0:
                # If zero, move to end of array and decrement
                nums.append(nums.pop(right_index))
                # Found a zero at the end, increment the left index since we append a zero at the end (shifted towards the right)
                left_index += 1
            else:
                # Neither points at zero, move pointers towards each other
                left_index += 1
                right_index -= 1
                
        return None
    
    @staticmethod
    def move_zeros_2(nums: List[int]) -> None:
        last_non_zero_found_at = 0
        for i in range(len(nums)):
            # If the current element does not equal to zero, run this block
            if nums[i] != 0:
                # If the current index does not equal to the index of the last non-zero found, make a swap
                if i != last_non_zero_found_at:
                    nums[i], nums[last_non_zero_found_at] = nums[last_non_zero_found_at], nums[i]
                # Increments the position to insert the next non-zero element, ensuring non-zeros are moved upfront, preserving their order
                last_non_zero_found_at += 1


def main() -> int:
    
    nums_1 = [0, 1, 0]
    nums_2 = [0, 1, 0, 3, 12]
    
    solution = Solution()
    
    print(f"The inputs are {nums_1} and {nums_2}")
    solution.move_zeros_1(nums_1)
    solution.move_zeros_2(nums_2)
    print(f"The results are {nums_1} and {nums_2}")

    return 0

if __name__ == "__main__":

    main()
