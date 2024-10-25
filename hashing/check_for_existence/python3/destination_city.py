from collections import defaultdict
from typing import List


def dest_city(paths: List[List[str]]) -> str:
    """
    Given an array of paths, where `paths[i] = [cityA_i, cityB_i]` means there exists a direct path going from `cityA_i` to `cityB_i`. Return the destination city, 
    that is, the city without any path outgoing to another city.
    
    Note: It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

    Parameters
    ----------
    paths : List[List[str]]
        A list of lists of strings, each of which is a dep -> dest pair of cities

    Returns
    -------
    str
        Name of the destination city
    """
    dest_count = defaultdict(int)
    # Cost O(n) to build
    for dep, dest in paths:
        # Decrement if city is a departure
        dest_count[dep] -= 1
        # Increment if city is a destination
        dest_count[dest] += 1
    
    # Find the city that has > 0 count, that is the destination
    for dep, dest in paths:
        # Access is O(1)
        if dest_count[dest] > 0:
            return dest
    # Never gets here if solution is guaranteed
    return ''
    
    
def main() -> int:
    
    paths = [["London", "New York"], ["New York", "Lima"], ["Lima", "Sao Paulo"]]
    destination = dest_city(paths)
    print(f"Given paths {paths}, the destination city is {destination}")
    
    return 0
    
if __name__ == "__main__":
    
    main()
