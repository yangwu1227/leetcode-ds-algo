def is_subsequence(s: str, t: str) -> bool:
    """
    Given two strings `s` and `t`, return True if `s` is a subsequence of `t`, or False otherwise.

    Parameters
    ----------
    s : str
        String for which to check if it is a subsequence of `t`.
    t : str
        String of which to check if `s` is a subsequence.

    Returns
    -------
    bool
        True if `s` is a subsequence of `t`, False if not.
    """
    s_index = t_index = 0

    # The loop completes when we have checked every single character in s or t
    while s_index < len(s) and t_index < len(t):
        if s[s_index] == t[t_index]:
            # We found a matching character in t, increment s_index to move on to next character in s
            s_index += 1

        # We always increment t so that the loop finishes when we exhausted t
        t_index += 1

    # We have found all characters in s in t if s_index is at the end of 's', otherwise not
    return s_index == len(s)


def main() -> int:
    true_case = {"s": "yang", "t": "yasdndfdfg"}
    false_case = {"s": "wu", "t": "wdfkjsdknfdfj"}

    for case in [true_case, false_case]:
        print(
            f"The string {case['s']} is a subsequence of {case['t']}: {is_subsequence(case['s'], case['t'])}"
        )

    return 0


if __name__ == "__main__":
    main()
