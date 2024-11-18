from collections import defaultdict
from string import ascii_lowercase

import numpy as np


def longest_substring(s: str, k: int) -> int:
    """
    Given a string `s` and an integer `k`. Find the length of the longest substring that contains at most `k` distinct characters.

    Parameters
    ----------
    s : str
        A string of lowercase English letters
    k : int
        An integer

    Returns
    -------
    int
        The length of the longest substring that contains at most `k` distinct characters
    """
    counts = defaultdict(int)
    left = window_len = 0
    for right in range(len(s)):
        # Slide the window forward
        counts[s[right]] += 1
        # Check if the window has become invalid (i.e. more than k distinct characters)
        while len(counts) > k:
            # Decrement the count of the character the left pointer points to
            counts[s[left]] -= 1
            # If this count becomes zero, remove the key from the map
            if counts[s[left]] == 0:
                del counts[s[left]]
            # Increment the left pointer
            left += 1
        # Check if the answer should be updated
        window_len = max(window_len, right - left + 1)
    return window_len


def main() -> int:
    letters = list(ascii_lowercase)
    for _ in range(4):
        length = np.random.randint(low=4, high=15)
        s = "".join(np.random.choice(a=letters, size=(length,)))
        k = np.random.randint(low=1, high=length - 2)
        ans = longest_substring(s, k)
        print(
            f"Given the string {s} and k = {k}, the longest substring with {k} distinct character has length {ans}"
        )

    return 0


if __name__ == "__main__":
    main()
