from collections import defaultdict
from collections.abc import Sequence

import numpy as np


def find_max_length(nums: Sequence[int]) -> int:
    """
    Given a binary array `nums`, return the maximum length of a contiguous subarray with an equal number of `0` and `1`.

    Parameters
    ----------
    nums : Sequence[int]
        A binary array containing 0's and 1's

    Returns
    -------
    int
        Maximum length of a continuous subarray
    """
    if len(nums) == 1:
        return 0
    max_len = count = 0
    hash_map = defaultdict(int)
    # Need to initialize count 0 at index -1, so if we encounter a count of 0 at some later index i, the subarray length is (i - (-1)) = i + 1
    # E.g., if by index 5 we have the same number of 1's and 0's, (5 - (-1)) = 6, the first 6 elements form a valid subarray
    hash_map[0] = -1
    for index, num in enumerate(nums):
        # Increment count if 1 or decrement if 0
        count += 1 if num else -1
        
        # Because we can only increment and decrement, the fact that hash_map[count] exists means that count has returned to a previously seen value
        # This means that the increase and decrease in counts have balanced each other out between the previous and current indices (i.e. same number of 1's and 0's)
        if count in hash_map:
            # If hash_map[count] is the index where the first time the value count was observed
            # Then, (current) index - hash_map[count] gives the length of this valid subarray
            max_len = max(max_len, index - hash_map[count])
        else:
            # If we have not since count previously, store the current index as the first occurrence of this count
            hash_map[count] = index
        
    return max_len

def main() -> int:
    
    for _ in range(5):
        n = np.random.choice(a=range(1, 15))
        nums = np.random.choice(a=[0, 1], size=n, replace=True).tolist()
        max_len = find_max_length(nums)
        print(f"Given the input {nums}, the maximum length of a contiguous subarray with an equal number of 0 and 1 is {max_len}")
        
    return 0

if __name__ == "__main__":
    
    main()
