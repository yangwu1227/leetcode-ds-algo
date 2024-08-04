from typing import Deque, List
from collections import deque

def smallest_string(s: str) -> str:
    """
    Given a string `s`, find the lexicographically smallest 
    string possible by moving characters to a new string following certain rules.

    Parameters
    ----------
    s : str
        The input string to be processed

    Returns
    -------
    str
        The lexicographically smallest string possible
    """
    if len(s) == 1:
        return s 
    
    original_deque: Deque[str] = deque(s)
    temp_deque: Deque[str] = deque()
    output: Deque[str] = deque()

    # Precompute the smallest characters to the right for each character in s
    # E.g., "yangwu" -> ['a', 'a', 'g', 'g', 'u', 'u']
    smallest_right: List[str] = [''] * len(s)
    # The smallest character to the right of the last character of 's' is always s[-1]
    smallest_right[-1] = s[-1]
    # Start with second to last character in 's' going from right to left (start = len(s) - 2, stop = -1, step = -1)
    for i in range(len(s) - 2, -1, -1):
        smallest_right[i] = min(s[i], smallest_right[i + 1])

    # Print initial state
    print(f"Initial state -> original_deque: {list(original_deque)}, temp_deque: {list(temp_deque)}, output: {list(output)}, smallest_right: {smallest_right}")

    while original_deque or temp_deque:
        if temp_deque:
            smallest_right_index = len(s) - len(original_deque)
            if smallest_right_index < len(smallest_right):
                comparison_char = smallest_right[smallest_right_index]
            else:
                comparison_char = ''
        else:
            comparison_char = ''
        
        # If temp_deque is not empty and (original_deque is empty or the top of temp_deque <= the smallest character in original_deque)
        if temp_deque and (not original_deque or temp_deque[-1] <= comparison_char):
            # The top of temp_deque can be safely popped and pushed to output
            print(f"Comparing temp_deque[-1] ({temp_deque[-1]}) <= smallest_right[{smallest_right_index}] ({comparison_char})") # type: ignore
            output.append(temp_deque.pop())
            action = "Pop from temp_deque to output"
        else:
            # Otherwise, move the first character from original_deque to temp_deque
            # This is done because either temp_deque is empty or there's a smaller character in original_deque yet to be processed to the right
            temp_deque.append(original_deque.popleft())
            action = "Move from original_deque to temp_deque"

        # Print state after each operation
        print(f"Action: {action} -> original_deque: {list(original_deque)}, temp_deque: {list(temp_deque)}, output: {list(output)}")
    
    return "".join(output)

def main() -> int:

    test_strings = ["bdda", "zza", "a", "yangwupython"]
    for s in test_strings:
        new_string = smallest_string(s)
        print(f"Original string: {s}")
        print(f"New string: {new_string}")
        print('\n')

    return 0

if __name__ == "__main__":

    main()
