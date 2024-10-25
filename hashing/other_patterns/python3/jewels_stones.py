from collections import Counter


class JewelStones(object):
    """
    Given two strings `jewewls` and `stones`, return the number of `stones` that are considered `jewels`.

    Parameters
    ----------
    jewels : str
        A sring consisting of lower and upper english letters, representing the unique types of stones that are considered `jewels`
    stones : str
        A string consisting of lower and upper english letters, representing the `stones`

    Returns
    -------
    int
        Number of `stones` that are considered `jewels`
    """
    @staticmethod
    def hashmap_approach(jewels: str, stones: str) -> int:
        # O(n) where n is the number of stones  
        stone_counts = Counter(stones)
        num_jewels = 0
        # O(m) where m is the number of unique stone types
        for jewel in jewels:
            num_jewels += stone_counts[jewel]
        return num_jewels
    
    @staticmethod
    def set_approach(jewels: str, stones: str) -> int:
        # Build the set in O(m) time
        jewel_set = set(jewels)
        # O(n) to iterate through stones
        return sum(stone in jewel_set for stone in stones)

def main() -> int:

    for jewels, stones in [("aA", "aAAbbbb"), ("z", "ZZ"), ("yangwu", "yangcpppythonR")]:
        num_jewels_hashmap = JewelStones.hashmap_approach(jewels, stones)
        num_jewels_set = JewelStones.set_approach(jewels, stones)
        assert num_jewels_hashmap == num_jewels_set
        print(f"Given jewels = '{jewels}' and stones = '{stones}', there are {num_jewels_set} stones that are considered jewels")

    return 0

if __name__ == "__main__":

    main()