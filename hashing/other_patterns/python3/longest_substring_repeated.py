from collections import defaultdict


class LongestSubstringRepetead(object):
    """
    Given a string `s`, find the length of the longest substring without repetaed characters.

    Parameters
    ----------
    s : str
        A string contining upper or lower case english characters, digits, symbols, and spaces

    Returns
    -------
    int
        Length of the longest valid subarray
    """

    @staticmethod
    def hash_map(s: str) -> int:
        left = window_len = 0
        character_counts: defaultdict[str, int] = defaultdict(int)
        # O(2n) visits to each character
        for right in range(len(s)):
            # Expand the window
            character_counts[s[right]] += 1
            # If any previously seen character exceeds a count of 1
            while character_counts[s[right]] > 1:
                # Shrink the window by decrementing the count of the character pointed to by the left pointer
                character_counts[s[left]] -= 1
                left += 1
            # Check if we have found a larger window
            window_len = max(window_len, right - left + 1)
        return window_len

    @staticmethod
    def sliding_window_optimized(s: str) -> int:
        left = window_len = 0
        character_indices: defaultdict[str, int] = defaultdict(int)
        # May be less than O(2n) visits to each character
        for right in range(len(s)):
            # If we have already seen this character before
            if s[right] in character_indices:
                # Set the left pointer to either the index of the last occurrence of this character or just its current value, whichever is further to the right
                left = max(character_indices[s[right]], left)
            window_len = max(window_len, right - left + 1)
            # For the character s[right], update its value in the map to be the next index
            character_indices[s[right]] = right + 1
        return window_len


def main() -> int:
    for s in ["abcabcbb", "bbbbb", "Aa !@@!abdsc"]:
        length_sliding_window = LongestSubstringRepetead.sliding_window_optimized(s)
        length_hash_map = LongestSubstringRepetead.hash_map(s)
        assert length_sliding_window == length_hash_map
        print(
            f"Given the string '{s}', the longest subarray without repeated characters has {length_hash_map} elements"
        )

    return 0


if __name__ == "__main__":
    main()
