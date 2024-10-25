from collections import defaultdict
from collections.abc import Sequence
from typing import List, Union


def group_anagrams(strs: Sequence[str]) -> List[Union[List[str], str]]:
    """
    Given an array of strings `strs`, group the anagrams together.
    
    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using
    all the original letters exactly once.

    Parameters
    ----------
    strs : Sequence[str]
        A sequence of strings

    Returns
    -------
    List[Union[List[str], str]]
        List of lists, each of which contains strings that are anagrams of each other
    """
    if len(strs) == 1:
        return list(strs)
    
    # Hash map with list as default factory function
    results = defaultdict(list)
    for string in strs:
        # O(c + c log c) where c is the length of each string
        sorted_string = ''.join(sorted(string))
        # O(1)
        results[sorted_string].append(string)
    
    return list(results.values())
    
def main() -> int:
    
    for strs in [("eat", "tea", "tan", "ate", "nat", "bat"), [""], ["a"], ("zhf", "fhz", "cpp", "python", "pcp", "statistics", "math", "tmah")]:
        results = group_anagrams(strs)
        print(f"Given the input {strs}, the results are as follows: {results}")
        
    return 0

if __name__ == "__main__":
    
    main()
