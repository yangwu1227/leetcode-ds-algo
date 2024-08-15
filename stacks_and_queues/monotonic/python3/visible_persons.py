from typing import MutableSequence, List, Deque 
from collections import deque

def visible_persons(heights: MutableSequence[int]) -> List[int]:
    """
    Calculate the number of people each person can see to their right in a queue.

    This function uses a monotonic stack approach to determine how many people
    each person in the queue can see to their right. A person can see another person
    to their right if all people between them are shorter than both of them.

    Parameters
    ----------
    heights : MutableSequence[int]
        A sequence of distinct integers where each integer represents the height of a person standing in a queue

    Returns
    -------
    List[int]
        A list of integers where the ith element represents the number of people the ith person can see to their right in the queue
    """
    if len(heights) == 1:
        return [0]
    monotonic_decreasing: Deque[int] = deque()
    output: List[int] = [0] * len(heights)
    # Traverse the queue from right to left
    for i in range(len(heights) - 1, -1, -1):
        # Initialize visible count to 0 for person i
        visible = 0
        # As long as the stack is non-empty and the top of the stack person is shorter than the current person, i.e., he is visible to the current person
        while monotonic_decreasing and heights[monotonic_decreasing[-1]] < heights[i]:
            # Increment the visible count of person `i` and pop this shorter person from the stack since they are seen now
            visible += 1
            monotonic_decreasing.pop()
        # If the stack is non-empty after the while loop finishes, then the top of the stack is the last visible person to the right of current person, add him to the count
        if monotonic_decreasing:
            visible += 1
        output[i] = visible
        monotonic_decreasing.append(i)
    return output

def main() -> int:

    data = [[9, 10, 7, 2, 12, 13, 17], [10, 6, 8, 5, 11, 9], [12]]
    for heights in data:
        output = visible_persons(heights)
        print(f"Given heights = {heights}, the visibility array is {output}")

    return 0

if __name__ == "__main__":

    main()
