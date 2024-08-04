from typing import List

def validate_stack(pushed: List[int], popped: List[int]) -> bool:
    """
    Determine if `pushed` and `popped` can be obtained from a series of stack push and pop operations.

    Parameters
    ----------
    pushed : List[int]
        A series of pushed elements in the specified order
    popped : List[int]
        A series of popped elements in the specified order

    Returns
    -------
    bool
        `True` if the sequences of operations are valid, `False` otherwise
    """
    if len(pushed) == 1:
        return pushed[0] == popped[0]

    stack: List[int] = []
    pop_index = 0
    # For all elements in pushed
    for val in pushed:
        # Push to empty stack
        stack.append(val)
        # As long as stack is not empty and the top element is the same as current popped element
        while stack and stack[-1] == popped[pop_index]:
            # Pop the top of the stack
            stack.pop()
            # Increment the index to consider the next popped element
            pop_index += 1

    # If stack is empty, the sequence is valid, if not, it is not valid
    return not stack

def main() -> int:

    test_cases = [
        ([1, 2, 3, 4, 5], [4, 5, 3, 2, 1]),
        ([1, 2, 3, 4, 5], [4, 3, 5, 1, 2]),
        ([2], [3])
    ]
    for pushed, popped in test_cases:
        valid = validate_stack(pushed, popped)
        print(f"Given pushed = {pushed} and popped = {popped}, these sequences are {'valid' if valid else 'not valid'}")

    return 0

if __name__ == "__main__":

    main()
