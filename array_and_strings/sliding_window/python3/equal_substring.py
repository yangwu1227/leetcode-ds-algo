def equal_substring(s: str, t: str, max_cost: int) -> int:
    """
    Given two strings `s` and `t` of the same length and an integer `max_cost`, change `s` to `t`, change `s` to `t`.
    Changing the ith character of `s` to ith character of `t` costs `|s[i] - t[i]|` (i.e., the absolute difference between
    the ASCII values of the characters). Return the maximum length of a substring of `s` that can be changed to be the
    same as the corresponding substring of `t` with a cost less than or equal to `max_cost`. If there is no substring
    from `s` that can be changed to its corresponding substring from `t`, return 0.

    Parameters
    ----------
    s : str
        A string consisting of lowercase english letters
    t : str
        A string consisting of lowercase english letters
    max_cost : int
        An integer representing the maximum cost allowed to change `s` to `t`

    Returns
    -------
    int
        The maximum length of a substring of `s` that can be changed to be the same as the corresponding substring of `t`
        with a cost less than or equal to `max_cost`
    """
    # O(n) operation to convert strings to lists of characters
    s_list = list(s)
    t_list = list(t)

    cost = left = window_len = 0
    for right in range(len(s_list)):
        cost += abs(ord(s_list[right]) - ord(t_list[right]))
        # Check if the window has become invalid, i.e., cost > max_cost
        while cost > max_cost:
            # Shrink window by removing elements (and their costs)
            cost -= abs(ord(s_list[left]) - ord(t_list[left]))
            # Increment left pointer
            left += 1
        # If the current window length is > the previous, update answer
        window_len = max(window_len, right - left + 1)

    return window_len


def main() -> int:
    s = "abcd"
    t = "bcdf"
    max_cost = 3

    window_len = equal_substring(s, t, max_cost)

    print(
        f"Given s = '{s}', t = '{t}', and max cost = {max_cost}, the maximum length of a substring of 's' that can be changed to be the same as the corresponding substring of 't' is {window_len}"
    )

    return 0


if __name__ == "__main__":
    main()
