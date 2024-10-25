from collections import Counter
from collections.abc import Sequence


def count_elements(array: Sequence[int]) -> int:
    """
    Given an integer `array`, count how many elements `x` there are, such that `x + 1` is also in `array`. If there are duplicates in `array`, count them separately.

    Parameters
    ----------
    array : Sequence[int]
        An integer array 

    Returns
    -------
    int
        Number of elements `x` such that `x + 1` is also in the array
    """
    # Create a hash map of element -> counts
    counter = Counter(array)
    for value in array:
        # If x + 1 not in hash table, which costs O(1) to check
        if not value + 1 in counter:
            # Decrement the counter for that element
            counter[value] -= 1
    return counter.total()

def main() -> int:
    
    array = (1, 2, 3, 3, 5, 5, 6, 7)
    result = count_elements(array)
    print(f"There are {result} number of elements in {array} satisfying the condition")
    
    return 0

if __name__ == "__main__":
    
    main()
