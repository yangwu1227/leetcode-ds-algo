from typing import List


def remove_duplicates(s: str) -> str:
    """
    Given a string `s`, remove all adjacent duplicate letters. 

    Parameters
    ----------
    s : str
        A string consisting of lower case english letters

    Returns
    -------
    str
        A string containing unique characters
    """
    if len(s) == 1:
        return s
    
    char_stack: List[str] = []
    for char in s:
        # If the stack is not empty and the top of the stack is the same as the current character
        if char_stack and char_stack[-1] == char:
                char_stack.pop(-1)
                continue
        # If stack is empty or the top of the stack is not the same as the current character, push the current character to the top
        char_stack.append(char)

    return ''.join(char_stack)

def main() -> int:

    test_strings = ["abbaca", "azxxzy", "tzzxlgqwwgyw", "gzzgtxwxxw"]
    for s in test_strings:
        unique_str = remove_duplicates(s)
        print(f"After removing all adjacent duplicates, '{s}' becomes '{unique_str}'")

    return 0
    
if __name__ == "__main__":

    main()
