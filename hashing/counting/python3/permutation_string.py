from collections import Counter


def check_inclusion(s1: str, s2: str) -> bool:
    """
    Given two strings `s1` and `s2`, return `True` if `s2` contains a permutation of `s1`.

    Parameters
    ----------
    s1 : str
        A string consisting of lower case english characters
    s2 : str
        A string consisting of lower case english characters

    Returns
    -------
    bool
        `True` if one of `s1`'s permutation is a substring of `s2`, `False` otherwise
    """
    len_s1 = len(s1)
    len_s2 = len(s2)
    if len_s1 > len_s2:
        return False
    # O(n) to build where n = len(s1)
    s1_counts = Counter(s1)
    # Initialized with first len(s1) characters of s2
    s2_window_counts = Counter(s2[slice(len_s1)])
    # O(m) where m = len(2) - len(s1)
    for window_end in range(len_s1, len_s2):
        # O(n) comparisons if every character in s1 is unique and both hashmaps contain n keys
        if s1_counts == s2_window_counts:
            return True
        # Add the next character or increment its count if already exists
        s2_window_counts[s2[window_end]] += 1
        # To keep the window fixed to len(s1), decrement the count of the element at (pointer - len(s1))
        window_start = window_end - len_s1
        s2_window_counts[s2[window_start]] -= 1
        # If the count of `s2[window_start]` reaches zero, delete the key so the comparison is more efficient
        if s2_window_counts[s2[window_start]] == 0:
            del s2_window_counts[s2[window_start]]
    # Last comparison is needed since the == check happens before inserting, incrementing, decrementing counts
    # The last iteration of the loop finished without comparing the last window of length len(s1) in s2
    return s1_counts == s2_window_counts


def main() -> int:
    for s1, s2 in [
        ["a", "ab"],
        ("ab", "eidbaooo"),
        ["ab", "eidboaoo"],
        ("adc", "dcda"),
    ]:
        contains_perm = check_inclusion(s1, s2)
        print(
            f"The string '{s2}' {'contains' if contains_perm else 'does not contain'} a permutation of the string '{s1}'"
        )

    return 0


if __name__ == "__main__":
    main()
