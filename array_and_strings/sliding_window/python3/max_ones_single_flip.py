def find_length(s: str) -> int:
    """ 
    Given a binary string s (a string containing only "0" and "1"). You may choose up to one "0" and flip it to a "1". Find the length of the longest substring 
    achievable that contains only "1". Another way to look at this problem is to find the longest substring that contains at most one 0. 
    
    Parameters
    ----------
    s : str
        A binary string containing only "0" and "1".
        
    Returns
    -------
    int
        The length of the longest substring achievable that contains only "1".
    """
    left = curr_zero_count = window_len = 0
    for right in range(len(s)):
        # If we encounter a 0, we can flip it to 1 and keep the consecutive "1"s going
        # But note down that we have encountered a 0
        if int(s[right]) == 0:
            curr_zero_count += 1
        # The window becomes invalid once we encounter more 0's we can no longer flip 
        # E.g. "01110", we can flip the first 0 but not the second
        # We keep shrinking the window until 'curr_zero_count' is < 1 again
        while (curr_zero_count > 1):
            # If the element the left pointer points to is zero, subtract from the zero counter since we've removed it by shrinking the window
            # If not, then we have removed a 1, and so the while loop continues 
            if int(s[left]) == 0:
                curr_zero_count -= 1
            left += 1

        window_len = max(window_len, right - left + 1)
        
    return window_len

def main() -> int:
    
    s = "11001011"
    window_len = find_length(s)
    
    print(f"The input '{s}' has a longest substring of {window_len} consecutive 1's if we flip one 0")

    return 0

if __name__ == "__main__":
    
    main()
