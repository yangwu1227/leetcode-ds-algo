from collections import Counter


def close_strings(first: str, second: str) -> bool:
    """
    Check if two strings are considered close. Two strings are close if one can be transformed into the other using the following operations:

    1. Swap any two existing characters in the string. Example: 'abcde' -> 'aecdb'
    2. Transform every occurrence of one character into another character and vice versa. Example: 'aacabb' -> 'bbcbaa' (all 'a's are transformed into 'b's and all 'b's into 'a's)

    Both operations can be used on either string as many times as necessary.

    Parameters
    ----------
    first : str
        A string containing lower case english characters
    second : str
        A string containing lower case english characters

    Returns
    -------
    bool
        `True` if `first` and `second` are close, otherwise `False`
    """
    if len(first) != len(second):
        return False
    # O(n) where n is the number of characters in both words
    first_counts, second_counts = Counter(first), Counter(second)
    # Check I: Both strings must contain the exact same unique characters, ensuring that characters can be swapped to match each other
    check_one = first_counts.keys() == second_counts.keys()
    # Check II: Both strings must have the same count distribution of characters, ensuring that characters can be transformed into each other
    check_two = sorted(first_counts.values()) == sorted(second_counts.values())
    return check_one and check_two


def main() -> int:
    for first, second in [
        ("abc", "bca"),
        ("a", "aa"),
        ("cabbba", "abbccc"),
        ("yangwucpp", "pythoncpp"),
    ]:
        close = close_strings(first, second)
        print(
            f"Given '{first}' and '{second}', the strings are{' ' if close else ' not '}close"
        )

    return 0


if __name__ == "__main__":
    main()
