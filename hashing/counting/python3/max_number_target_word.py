from collections import Counter
from sys import maxsize


def max_number_target_word(text: str, target_word: str) -> int:
    """
    Given a string `text`, use the characters of `text` to form as many instances of the word `target_word` as possible.

    Note: Use each character in text at most once.

    Parameters
    ----------
    text : str
        A string containing lower case english letters
    target_word : str
        A target word

    Returns
    -------
    int
        The maximum number of instances of the word `target_word` that can be formed
    """
    # O(n + m) to build
    char_counts = Counter(text)
    target_counts = Counter(target_word)

    # If text has fewer unique characters than target_word
    if len(char_counts) < len(char_counts):
        return 0

    max_num_instances = maxsize
    # Iterate through each character in the target word, compute number of times we can satisfy the minimum number of each character needed to form the target word
    # E.g. target_counts = {'a': 2} (two letter 'a' required) and char_counts = {'a': 6}, then 6 // 2 = 3, then we can potentially form up to three instances of target word
    for char in target_counts:
        # If a key is not found, 0 is the default, which means that no instance of the word can be formed
        if char_counts[char] == 0:
            return 0
        num_time_satisfied = char_counts[char] // target_counts[char]
        # Keep updating the minimum, i.e., we can't form more instances than any character's maximum potential allows
        max_num_instances = min(max_num_instances, num_time_satisfied)

    return max_num_instances


def main() -> int:
    texts = ["nlaebolko", "loonbalxballpoon", "leetcode", "balon"]
    for text in texts:
        max_num = max_number_target_word(text, "balloon")
        starting_message = f"Given the input {text}"
        ending_message = "the word 'balloon' from its characters"
        if max_num:
            print(
                f"{starting_message}, there can at most {max_num} instances of {ending_message}"
            )
        else:
            print(
                f"{starting_message}, it is not possible to form the {ending_message}"
            )

    return 0


if __name__ == "__main__":
    main()
