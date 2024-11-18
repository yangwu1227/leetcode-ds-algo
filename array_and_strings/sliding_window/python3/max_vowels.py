def max_vowels(s: str, k: int) -> int:
    """
    Given a string `s` and an integer `k`, return the maximum number of vowel letters in any substring of `s` with length `k`.

    Note: Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

    Parameters
    ----------
    s : str
        A string
    k : int
        An integer

    Returns
    -------
    int
        The maximum number of vowel letters in any substring of `s` with length `k`
    """
    # O(n) operation to convert string to list of characters
    s = list(s)
    # Use a set since checking 'x' in 'vowels' is O(1) average
    vowels = {"a", "e", "i", "o", "u"}

    vowel_count = 0
    # First fixed window
    for right in range(k):
        # If a vowel, add to the count
        if s[right] in vowels:
            vowel_count += 1
    # After first window, update the answer
    ans = vowel_count
    # Slide window towards the right
    for right in range(k, len(s)):
        # If a vowel, add to the count
        if s[right] in vowels:
            vowel_count += 1
        # Only subtract from the count if the element removed from the window is a vowel
        if s[right - k] in vowels:
            vowel_count -= 1
        # Update answer if the current vowel count is greater than the previous
        ans = max(ans, vowel_count)

    return ans


def main() -> int:
    s = "abciiidef"
    k = 3

    result = max_vowels(s, k)

    print(
        f"Given the input string {s} and k = {k}, the maximum number of vowel letters in any substring of length {k} is {result}"
    )

    return 0


if __name__ == "__main__":
    main()
