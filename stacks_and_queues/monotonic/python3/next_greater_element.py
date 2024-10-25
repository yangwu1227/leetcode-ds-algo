from array import array
from collections import defaultdict
from typing import List, MutableMapping, MutableSequence


def next_greater_element(nums_1: MutableSequence[int], nums_2: MutableSequence[int]) -> List[int]:
    """
    Given two distinct integer arrays `nums_1` and `nums_2` where `nums_1` is a subset of `nums_2`, 
    find the array `output` such that for each element `nums_1[i]`, `output[i]` contains the next greater element
    of `nums_1[i]` in `nums_2`. If no such element exists, `output[i]` will be -1.

    Parameters
    ----------
    nums_1 : MutableSequence[int]
        A sequence of integers that is a subset of `nums_2`
    nums_2 : MutableSequence[int]
        A sequence of integers where `nums_1` is a subset, used to determine the next greater element for each element in `nums_1`

    Returns
    -------
    List[int]
        A list where each element corresponds to the next greater element of the respective element in 
        `nums_1` found in `nums_2`; if there is no greater element, the corresponding value will be -1
    """
    next_greater_map: MutableMapping[int, int] = defaultdict(lambda: -1)
    monotonic_increasing: MutableSequence[int] = array('I')
    for element in nums_2:
        # While the stack is non-empty and the current element maintains the monotonic increasing property
        while monotonic_increasing and element > monotonic_increasing[-1]:
            # Pop the previous element and map it to its next greater element, i.e., the current element
            next_greater_map[monotonic_increasing.pop(-1)] = element
        monotonic_increasing.append(element)
    # For any element in `nums_1` with no explicit mapping, defaults to -1
    output = [next_greater_map[element] for element in nums_1]
    return output

def main() -> int:

    data = [
        ([1, 3, 5, 7, 9], [9, 7, 5, 3, 1]),
        ([4, 1, 2], [1, 3, 4, 2]),
        ([5, 7, 1], [2, 3, 5, 1, 0, 7, 3])
    ]
    for nums_1, nums_2 in data:
        output = next_greater_element(nums_1, nums_2)
        print(f"Given nums 1 = {nums_1} and nums 2 = {nums_2}, the output is {output}")

    return 0

if __name__ == "__main__":

    main()
