from collections import defaultdict

def isomorphic(s: str, t: str) -> bool:
    """
    Given two strings `s` and `t`, determine if they are isomorphic. Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced to get `t`.

    Note: All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same 
    character, but a character may map to itself.

    Parameters
    ----------
    s : str
        A string containing valid ASCII characters
    t : str
        A string containing valid ASCII characters

    Returns
    -------
    bool
        `True` if `s` and `t` are isomophic, other wise `False`
    """
    s_to_t = defaultdict(str)
    t_to_s = defaultdict(str)
    for char_s, char_t in zip(s, t):
        # Check I: If the current s_char is already mapped to a character in t
        if char_s in s_to_t:
            # Check if s_char maps to the same character as the current char_t
            if s_to_t[char_s] != char_t:
                # If not, then s and t cannot be isomorphic, since the same s_char is mapped to two different characters in t
                # E.g., s = 'eeg' and t = 'edg', where 'e' in s is mapped to 'e' and 'd' in t
                return False
        # Check II: If the current s_char has not been mapped to a character in t yet, but the current t_char has already been mapped to by some char_s
        elif char_t in t_to_s:
            # Check if a different (previously seen) s_char has already mapped to this current char_t
            if t_to_s[char_t] != char_s:
                # If so, then s and t cannot be isomorphic, since two different s_char's are mapped to the same character in t
                # E.g., s = 'bbaaba' and t = 'aabbba', where both 'a' and 'b' in s are mapped to the same character 'b' in t
                return False
        else:
            # Neither char_s nor char_t is currently associated with any characters, so we create a bidirectional mapping between char_s and char_t
            s_to_t[char_s] = char_t
            t_to_s[char_t] = char_s 
    return True
    
def main() -> int:

    for s, t in [("egg", "add"), ("paper", "title"), ("foo", "bar"), ("bbbaaaba", "aaabbbba")]:
        iso = isomorphic(s, t)
        print(f"Given s = '{s}' and t = '{t}', these strings are{'' if iso else ' not'} isomorphic to each other")

    return 0

if __name__ == "__main__":

    main()