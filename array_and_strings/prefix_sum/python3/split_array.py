from collections.abc import Sequence


def split_array(nums: Sequence[int]) -> int:
    """
    Given an integer array `nums`, find the number of ways to split the array into two parts so that the first section has a 
    sum greater than or equal to the sum of the second section. The second section should have at least one number.

    Parameters
    ----------
    nums : Sequence[int]
        An array of integers

    Returns
    -------
    int
        Number of ways to split the array into two parts while satisfying the criteria: `first_section_sum >= second_section_sum`
    """
    valid_splits = 0

    # Build prefix O(n)
    prefix = [nums[0]]
    for i in range(1, len(nums)):
        # Append is O(1)
        prefix.append(prefix[-1] + nums[i])

    # Use len(prefix) - 1, since the second section must have at least 1 number
    for i in range(len(prefix) - 1):
        # Left sum is just the sum up to the ith element in `nums`
        left_sum = prefix[i]
        # Since prefix[-1] is the sum of all elements in `nums`
        # Subtract prefix[i] we get the sum of elements i + 1 through n
        right_sum = prefix[-1] - prefix[i]
        valid_splits += (left_sum >= right_sum)

    return valid_splits


def main() -> int:

    arrays = [[10, 4, -8, 7], (2, 3, 1, 0)]
    for array in arrays:
        valid_splits = split_array(array)
        print(f"Given input array {array}, there are {valid_splits} number of splits so that the sum of the first section is >= sum of the second section")

    return 0


if __name__ == "__main__":

    main()
