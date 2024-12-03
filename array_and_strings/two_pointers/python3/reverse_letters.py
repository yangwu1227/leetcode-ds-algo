def reverse_letters(s: str) -> str:
    """
    Given a string s, reverse the string according to the following rules:

    1. All the characters that are not English letters remain in the same position.
    2. All the English letters (lowercase or uppercase) should be reversed.

    Parameters
    ----------
    s: str
        Input string

    Returns
    -------
    str
        Reversed string.
    """
    left_index = 0
    right_index = len(s) - 1

    # List of characters
    s_list = list(s)
    while left_index < right_index:
        if s_list[left_index].isalpha() and s_list[right_index].isalpha():
            # Both pointers point at letters, reverse and move pointers
            s_list[left_index], s_list[right_index] = s_list[right_index], s_list[left_index]
            left_index += 1
            right_index -= 1
        elif not s_list[left_index].isalpha():
            # If the left pointer points at a non-letter, increment
            left_index += 1
        elif not s_list[right_index].isalpha():
            # If the right pointer points at a non-letter, decrement
            right_index -= 1

    # Concatenate back to a string
    return "".join(s_list)


def main() -> int:
    s_1 = "ab-cd"
    s_2 = "a-bC-dEf-ghIj"
    s_3 = "Test1ng-Leet=code-Q!"

    for s in [s_1, s_2, s_3]:
        result = reverse_letters(s)
        print(f"The input string {s} is changed to {result}")

    return 0


if __name__ == "__main__":
    main()
