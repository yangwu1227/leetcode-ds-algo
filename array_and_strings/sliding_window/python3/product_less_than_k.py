from typing import List


def num_subarrays_product_less_than_k(nums: List[int], k: int) -> int:
    """
    Given an array of positive integers nums and an integer k, return the number of subarrays where the product of all the elements in the subarray is strictly less than k.

    Parameters
    ----------
    nums : List[int]
        A list of positive integers
    k : int
        An integer

    Returns
    -------
    int
        The number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
    """
    # If k <= 1, there is no valid subarray where the product of its elements are strictly <= 1
    if k <= 1:
        return 0

    left = num_subarrays = 0
    curr_product = 1

    for right in range(len(nums)):
        # Current product of all elements in the current window
        curr_product *= nums[right]
        # The window becomes invalid once the product is no longer strictly less than k
        while curr_product >= k:
            # Divide the current product by the element the left pointer points to, using // integer division
            curr_product //= nums[left]
            # Slide the window towards the right
            left += 1

        # Instead of updating, we add the current window size to the total number of subarrays variable
        # This is because given the current window (left, right), there are (right - left + 1) subarrays
        num_subarrays += right - left + 1

    return num_subarrays


def main() -> int:
    nums = [10, 5, 2, 6, 7]
    k = 35

    num_subarrays = num_subarrays_product_less_than_k(nums, k)

    print(
        f"The input {nums} with k = {k} contains {num_subarrays} subarrays where the product of all its elements is strictly less than k"
    )

    return 0


if __name__ == "__main__":
    main()
