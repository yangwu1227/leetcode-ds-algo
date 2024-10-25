from typing import List


def remove_stars(s: str) -> str:
    """
    For a string `s` with stars (*), repeatedly remove each star and its closest
    preceding character until no stars remain. 

    Parameters
    ----------
    s : str
        A string consisting of lower case english letters and "*"

    Returns
    -------
    str
        A new string with all characters preceding "*" removed
    """
    if len(s) == 1:
        return s
    char_stack: List[str] = []
    for char in s:
        if char_stack and char == '*':
            char_stack.pop(-1)
        else:
            char_stack.append(char)
    return "".join(char_stack)

def main() -> int:

    test_strings = ["leet**cod*e", "erase*****"]
    for s in test_strings:
        new_string = remove_stars(s)
        print(f"Original string is {s}")
        print(f"New string is {new_string if new_string else 'empty'}")
        print('\n')

    return 0

if __name__ == "__main__":

    main()
