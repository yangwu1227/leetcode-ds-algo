from collections import Counter
from collections.abc import Sequence


def num_identical_pairs(nums: Sequence[int]) -> int:
    """
    Given an array of integers `nums`, return the number of valid pairs. A pair of elements `(i, j)` is valid if `nums[i] == nums[j]` and `i < j`.

    Parameters
    ----------
    nums : Sequence[int]
        A sequence of positive integers

    Returns
    -------
    int
        Number of valid pairs of elements
    """
    # O(n) to build
    counts = Counter(nums)
    # O(k) with k = number of unique elements, which can be k = n in the worst case
    num_pairs = sum(((count * (count - 1)) // 2 for count in counts.values()), 0)
    return num_pairs

def main() -> int:
    
    for nums in [[1, 2, 3, 1, 1, 3], (1, 1, 1, 1), [0, 9, 7, 3, 2], (1, 2, 3, 1, 1, 3, 3)]:
        num_pairs = num_identical_pairs(nums)
        print(f"Given the input {nums}, there are {num_pairs} valid pairs")
        
    return 0

if __name__ == "__main__":
    
    main()
