from typing import List

def get_common(nums1: List[int], nums2: List[int]) -> int:
    """
    Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. 
    If there is no common integer amongst nums1 and nums2, return -1. Note that an integer is said to be common to nums1 and nums2 
    if both arrays have at least one occurrence of that integer.

    Parameters
    ----------
    nums1 : List[int]
        First input array of integers sorted in non-decreasing order.
    nums2 : List[int]
        Second input array of integers sorted in non-decreasing order.

    Returns
    -------
    int
        The minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.
    """
    i = j = 0
    
    # The loop finishes once one of the two arrays is exhausted
    # If no common integer is found when one array is exhausted
    # What's left in the other array can only be higher values
    # So a common integer is impossible, no need to ensure both arrays are exhausted
    while (i < len(nums1)) and (j < len(nums2)):
        
        if nums1[i] == nums2[j]:
            # If a match is found, just return either since remaining elements can only be larger
            return nums1[i]
        elif nums1[i] < nums2[j]:
            # If element j in array 2 is greater than element i in array 1
            # Increment i (the smaller index) since j can only point to a larger value
            i += 1
        elif nums2[j] < nums1[i]:
            # If element i in array 1 is greater than element j in array 2
            # Increment j (the smaller index) since i can only point to a larger value
            j += 1
        
    # If while completes without returning, no common value    
    return -1

def main() -> int:
    
    test_cases = {
        'test_case_1': {'nums1': [1, 2, 3], 'nums2': [2, 4]},
        'test_case_2': {'nums1': [1, 2, 3, 6], 'nums2': [2, 3, 4, 5]},
        'test_case_3': {'nums1': [1, 2, 3], 'nums2': [5, 7, 9]}
    }
    
    for key in test_cases:
        
        result = get_common(test_cases[key]['nums1'], test_cases[key]['nums2'])
        
        print(f"{test_cases[key]['nums1']} x {test_cases[key]['nums2']} shares {'nothing' if result == -1 else result}")
        
    return 0

if __name__ == "__main__":
    
    main()
