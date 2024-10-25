from collections import Counter


def sort_count(s: str) -> str:
    """
    Given a string `s`, sort it in decreasing order based on the count of its characters. The count of a character is the number of times it appears in the string.

    Parameters
    ----------
    s : str
        A string consisting of lower and upper case english letters as well as digits

    Returns
    -------
    str
        Sorted string in decreasing order based on the count of its characters
    """
    if len(s) == 1:
        return s
    # 0(n) to build
    char_counts = Counter(s)
    # Counter.most_common() is O(k log k), and char * count is effectively O(1) 
    repeated_chars = (char * count for char, count in char_counts.most_common())
    # For k unique characters, this is O(k)
    return ''.join(repeated_chars)

def main() -> int:

    for s in ("tree", "cccaaa", "Aabb"):
        sorted_s = sort_count(s)
        print(f"Given the string {s}, the sorted version of it is {sorted_s}")

    return 0

if __name__ == "__main__":

    main()
