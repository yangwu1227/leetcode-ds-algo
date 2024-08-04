from typing import List, Dict

def valid_parentheses(s: str) -> bool:
    """
    Given a string `s` containing characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. An input string is valid if:

    * Open brackets must be closed by the same type of brackets
    * Open brackets must be closed in the correct order
    * Every close bracket has a corresponding open bracket of the same type

    Parameters
    ----------
    s : str
        A string containig different types of parentheses

    Returns
    -------
    bool
        `True` if the string is valid, otherwise `False`
    """
    if len(s) == 1:
        return False

    parentheses_stack: List[str] = []
    matching_bracket: Dict[str, str] = {"(": ")", "[": "]", "{": "}"} 

    for curent_bracket in s:
        # If the current bracket is an open bracket, push it onto the stack 
        if curent_bracket in matching_bracket:
            parentheses_stack.append(curent_bracket)
        else:
            # If the stack is empty, there is no open bracket to match the current closing bracket, so the string is invalid
            if not parentheses_stack:
                return False

            last_open_bracket = parentheses_stack.pop(-1)
            # Check if the current closing bracket matches the last open bracket in the stack
            if matching_bracket[last_open_bracket] != curent_bracket:
                return False

    # If there are any remaining open brackets in the stack after the loop, the string is invalid
    return not parentheses_stack

def main() -> int:

    test_strings = ["()[]{}", "()", "(}", "]", "){"]
    for s in test_strings:
        is_valid = valid_parentheses(s)
        print(f"The string {s} {'is' if is_valid else 'is not'} valid")

    return 0

if __name__ == "__main__":

    main()
