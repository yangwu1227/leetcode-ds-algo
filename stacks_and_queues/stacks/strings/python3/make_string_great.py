from typing import List


def make_string_great(s: str) -> str:
    """
    Given a string `s` of lower and upper case English letters. Remove all adjacent characters that one lower case
    letter followed by an upper case letter, or vice versa. 
    
    Parameters
    ----------
    s : str
        A string containing lower case and upper case english characters

    Returns
    -------
    str
        A new string that satisfy the requirements of a good string
    """
    if len(s) == 0:
        return s

    str_stack: List[str] = []
    for char in s:
        # If the stack is not empty and the top character and the current character form a bad pair
        if str_stack and str_stack[-1].swapcase() == char:
            # Pop the top character and do not append the current
            str_stack.pop()
        else:
            str_stack.append(char)

    return "".join(str_stack)
    
def main() -> int:

    test_strings = ["leEeetcode", "abBAcC", "AdG"]
    for s in test_strings:
        new_s = make_string_great(s)
        print(f"The original string: {s}")
        print(f"The new string: {new_s if new_s else 'empty'}")
        print('\n')

    return 0

if __name__ == "__main__":

    main()
