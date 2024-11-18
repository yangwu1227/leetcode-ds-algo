from collections import defaultdict


def word_pattern(pattern: str, s: str) -> bool:
    """
    Given a `pattern` and a string `s`, find if `s` follows the `pattern`.

    Parameters
    ----------
    pattern : str
        A pattern consisting of lower case english characters
    s : str
        A string consisting of lower case english characters and single white spaces

    Returns
    -------
    bool
        `True` if `s` follows `pattern`, otherwise `False`
    """
    # O(n) where n is the length of 's'
    words = s.split(sep=" ")
    if len(words) != len(pattern):
        return False
    pattern_to_word = defaultdict(str)
    word_to_pattern = defaultdict(str)
    # O(m) where m is the length of 'pattern'
    for pat_char, word in zip(pattern, words):
        # If pattern character already has an associated word
        if pat_char in pattern_to_word:
            # Check if pattern character is associated with the current word
            if pattern_to_word[pat_char] != word:
                # If not, it means that the same pattern character is associated with two different words, making it impossible for 's' to follow 'pattern'
                return False
        # If pattern character does not yet have an associated word, check if the current word already has another pattern character associated with it
        elif word in word_to_pattern:
            # If so, check if that that pattern character, which is associated with the current word, is the same as the current pattern character
            if word_to_pattern[word] != pat_char:
                # If not, it means that there are two different pattern characters associated with the same word, again making it impossible for 's' to follow 'pattern'
                return False
        else:
            # Just create the mappings
            pattern_to_word[pat_char] = word
            word_to_pattern[word] = pat_char
    # If loop completes, then 's' follows 'pattern'
    return True


def main() -> int:
    for pattern, s in [
        ("abba", "dog cat cat dog"),
        ("aaaa", "dog cat cat dog"),
        ["aaa", "aa aa aa aa"],
    ]:
        follows_pattern = word_pattern(pattern, s)
        print(
            f"Given s = '{s}' and pattern = {pattern}, 's' {'follows' if follows_pattern else 'does not follow'} 'pattern'"
        )

    return 0


if __name__ == "__main__":
    main()
