from collections import defaultdict


def repeated_character(s: str) -> str:
    """
    Given a string `s` consisting of lowercase English letters, return the first letter to appear twice.

    Parameters
    ----------
    s : str
        A string containing lowercase english characters

    Returns
    -------
    str
        The fist character to appear twice
    """
    d = defaultdict(int)
    for char in s:
        d[char] += 1
        # Once the count for a char becomes greater than 1, return
        if d[char] > 1:
            return char
    # Will never get here if `s` is guaranteed to contain at least one solution
    return ""


def main() -> int:
    strings = ["abccbaacz", "abcdd", "yangwulovespythonandcpp"]
    for s in strings:
        char = repeated_character(s)
        print(f"Given the string {s}, the first letter to appear twice is {char}")

    return 0


if __name__ == "__main__":
    main()
