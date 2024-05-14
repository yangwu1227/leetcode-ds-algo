from collections.abc import Sequence
from collections import Counter

def largest_unique_number(nums: Sequence[int]) -> int:
    """
    Given an integer array `nums`, return the largest integer that only occurs once. If no integer occurs once, return `-1`.

    Parameters
    ----------
    nums : Sequence[int]
        A list of positive integers

    Returns
    -------
    int
        Largest integer that appeared once or -1 if no such integer exist
    """
    # Cost O(n) to build
    counter = Counter(nums)
    
    max_int = -1
    # O(n) to check
    for num, count in counter.items():
        if count == 1:
            max_int = max(max_int, num)
    
    return max_int
    
def main() -> int:
    
    for nums in [[5, 7, 3, 9, 4, 9, 8, 3, 1], [9, 9, 8, 8]]:
        max_int = largest_unique_number(nums)
        print(f"Given the input {nums}, the largest unique integer {'does not exist' if max_int == -1 else f'is {max_int}'}")
        
    return 0

if __name__ == "__main__":
    
    main()
    