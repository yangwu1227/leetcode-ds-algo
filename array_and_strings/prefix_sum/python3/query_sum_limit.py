from collections.abc import Sequence
from typing import List


def query_sum_limit(
    nums: Sequence[int], queries: Sequence[Sequence[int]], limit: int
) -> List[bool]:
    """
    Given an integer array `nums`, an array `queries` where `queries[i] = [x, y]` and an integer `limit`, return a boolean array that represents the answer to each query.
    Each query is of the form `queries[i] = [x, y]` where `0 <= x < y < len(nums)`.

    Parameters
    ----------
    nums : Sequence[int]
        An integer array
    queries : Sequence[Sequence[int]]
        An array of queries where `queries[i] = [x, y]`
    limit : int
        An integer value representing the limit

    Returns
    -------
    List[bool]
        A boolean array that represents the answer to each query
    """
    # Build prefix array, costs O(n)
    prefix = [nums[0]]
    for i in range(1, len(nums)):
        # Prefix[i - 1] is the sum up to the (i - 1) index, to which we add the ith element
        prefix.append(prefix[i - 1] + nums[i])  # Append is O(1)

    ans = []
    for query in queries:
        # Use indexing since it is O(1), alternatively we can just unpack: left, right = query
        left, right = query[0], query[1]
        subarray_sum = prefix[right] - prefix[left] + nums[left]
        less_than_limit = subarray_sum < limit
        ans.append(less_than_limit)

    return ans


def main() -> int:
    nums = (1, 6, 3, 2, 7, 2, 10, 14, 4, 8, 7, 2, 3, 1, 0, 3)
    queries = ([0, 2], [2, 5], [2, 6], (2, 9), (11, 14), [10, 12])
    limit = 13
    ans = query_sum_limit(nums, queries, limit)
    print(f"Given nums = {nums}, queries = {queries}, and limit = {limit}, the answer is {ans}")

    return 0


if __name__ == "__main__":
    main()
