from typing import List
from random import sample

def combine(arr1: List[int], arr2: List[int], exhaust_method: int) -> List[int]:
    """
    Given two 'sorted' integer arrays arr1 and arr2, return a new array that combines both of them 
    and is also sorted.

    Parameters
    ----------
    arr1 : List[int]
        First sorted input array.
    arr2 : List[int]
        Second sorted input array.
    exhaust_method: int
        1 for while loop method and 0 or if block method for exhausting the arrays.

    Returns
    -------
    List[int]
        Sorted array that is the combination of the input arrays.
    """
    arr1_index = arr2_index = 0
    arr1_n = len(arr1)
    arr2_m = len(arr2)
    
    ans = []
    # After this finishes, one of the arrays will be exhausted
    while arr1_index < arr1_n and arr2_index < arr2_m:
        
        # Current elements
        curr_el_1 = arr1[arr1_index]
        curr_el_2 = arr2[arr2_index]
        
        if curr_el_1 < curr_el_2:
            # Current element of arr1 is smaller, append and increment
            ans.append(curr_el_1) 
            arr1_index += 1
        elif curr_el_1 > curr_el_2:
            # Current element of arr2 is smaller, append and increment
            ans.append(curr_el_2)
            arr2_index += 1
        else:
            # If ==, append and increment both
            ans.extend([curr_el_1, curr_el_2])
            arr1_index += 1
            arr2_index += 1
        
    if exhaust_method:
        # Exhaust arr1
        while arr1_index < arr1_n:
            curr_el_1 = arr1[arr1_index]
            ans.append(curr_el_1)
            arr1_index += 1
        
        # Exhaust arr2
        while arr2_index < arr2_m:
            curr_el_2 = arr2[arr2_index]
            ans.append(curr_el_2)
            arr2_index += 1
    else:
        # Exhaust arr1
        if arr1_index < arr1_n:
            ans.extend(arr1[arr1_index:])
        
        if arr2_index < arr2_m:
            ans.extend(arr2[arr2_index:])
        
    return ans
                 
def main() -> int:
    
    arr1 = sample(range(15, 25), 5)
    arr2 = sample(range(20, 60), 7)
    # This works on sorted input arrays
    arr1.sort()
    arr2.sort()
    
    combined_sorted_array_1 = combine(arr1, arr2, 1)
    combined_sorted_array_0 = combine(arr1, arr2, 0)
    
    assert combined_sorted_array_1 == combined_sorted_array_0
    
    print(f'Exhaust with while loop: {arr1} + {arr2} = {combined_sorted_array_1}')
    print(f'Exhaust with extend method: {arr1} + {arr2} = {combined_sorted_array_0}')
    
    return 0

if __name__ == "__main__":
    
    main()
