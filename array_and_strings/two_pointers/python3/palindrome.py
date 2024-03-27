def check_if_palindrome(s: str) -> bool:
    """
    Check if the input string is a palindrome.

    Parameters
    ----------
    s : str
        Input string.

    Returns
    -------
    bool
        True if palindrome and False if not.
    """
    if not isinstance(s, str):
        raise TypeError("The input must be a string")
    
    left_index = 0
    right_index = len(s) - 1
    
    while left_index < right_index:
        
        # If the pairs of characters are not equal
        if s[left_index] != s[right_index]:
            return False
        
        left_index += 1
        right_index -= 1
    
    # If while loop finishes (i.e., left_index == right_index), it is a palindrome
    return True

def main() -> int:
    
    palindrome = "racecar"
    
    not_palindrome = "soccer"
    
    print(f"The string {palindrome} is a palindrome: {check_if_palindrome(palindrome)}")
    print(f"The string {not_palindrome} is a palindrome: {check_if_palindrome(not_palindrome)}")
    
    return 0

if __name__ == "__main__":
    
    main()
