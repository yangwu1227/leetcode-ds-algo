from collections.abc import Sequence
from random import randint

def highest_altitude(gain: Sequence[int]) -> int:
    """
    A road trip consists of `n + 1` points at different altitudes. The start point is `altitude = 0`. Given an integer array `gain` of 
    length `n` where `gain[i]` is the net gain in altitude between points `i` and `i + 1` for all (`0 <= i < n`), return the highest altitude of a point.

    Parameters
    ----------
    gain : Sequence[int]
        An integer array `gain` of length `n` where `gain[i]` is the net gain in altitude between points `i` and `i + 1` for all (`0 <= i < n`)

    Returns
    -------
    int
        The highest altitude of a point
    """
    # Track current sum and find max in one go, which costs O(n)
    current_sum = 0
    highest_point = 0
    for val in gain:
        current_sum = current_sum + val
        # One comparison O(1)
        highest_point = max(highest_point, current_sum)
        
    return highest_point
    
def main() -> int:
    
    gain = [randint(a=-35, b=17) for _ in range(7)]
    highest_point =highest_altitude(gain)
    print(f"Given the gains array {gain}, the highest altitude is {highest_point}")
    
    return 0

if __name__ == "__main__":
    
    main()
