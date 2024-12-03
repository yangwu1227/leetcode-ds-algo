from typing import List


class Solution(object):
    """
    Given an integer array `nums` sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
    Using the two-pointers approach.

    Parameters
    ----------
    nums : List[int]
        Integer array sorted in non-decreasing order.

    Returns
    -------
    List[int]
        Squares of each number sorted in non-decreasing order.
    """

    def sorted_squares_while(self, nums: List[int]) -> List[int]:
        left_index = 0
        right_index = len(nums) - 1

        result: List[int] = []
        while left_index < right_index:
            left_squared = nums[left_index] ** 2
            right_squared = nums[right_index] ** 2

            # Always insert from the left since 'result' must be increasing order
            if left_squared < right_squared:
                # Insert the larger squared value and move right index towards left
                result.insert(0, right_squared)
                right_index -= 1
            elif right_squared < left_squared:
                # Insert the larger squared value and move left index towards right
                result.insert(0, left_squared)
                left_index += 1
            else:
                # If tied, insert both and move both indices towards each other
                result.insert(0, left_squared)
                result.insert(0, right_squared)
                right_index -= 1
                left_index += 1

        # Once the loop completes, check if there is any remaining element
        # Append this smallest squared value (both indices point to it so use either)
        if len(result) == len(nums) - 1:
            result.insert(0, nums[left_index] ** 2)

        return result

    def sorted_squares_for(self, nums: List[int]) -> List[int]:
        left_index = 0
        right_index = len(nums) - 1
        n = len(nums)

        result = [0] * n
        # Loop in reverse (stop at -1 so 0 is included and step is -1)
        for i in range(n - 1, -1, -1):
            left_abs = abs(nums[left_index])
            right_abs = abs(nums[right_index])

            if left_abs < right_abs:
                # If the right element's abs is larger, its squared value is larger
                right_index -= 1
                squares = right_abs**2
            else:
                # If the left element's abs is larger, its squared value is larger
                # This branch handles ties, adds the left squared and leaves right squared to next iteration
                left_index += 1
                squares = left_abs**2
            result[i] = squares

        return result


def main() -> int:
    nums_1 = [-7, -3, 2, 3, 11]
    nums_2 = [-4, -1, 0, 3, 10]

    solution = Solution()

    for nums in [nums_1, nums_2]:
        solution_1 = solution.sorted_squares_while(nums)
        solution_2 = solution.sorted_squares_for(nums)
        assert solution_1 == solution_2

        print(f"Input {nums} becomes {solution_1}")

    return 0


if __name__ == "__main__":
    main()
