def reverse_words(s: str) -> str:
    """
    Given a string `s`, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

    Parameters
    ----------
    s : str
        A string containing words separated by whitespace.

    Returns
    -------
    str
        A string with the order of characters in each word reversed while preserving whitespace and initial word order.
    """
    # Split Sentence into list of words
    list_of_words = s.split(sep=" ")

    result = []
    for word in list_of_words:
        left_index = 0
        right_index = len(word) - 1

        # Split the word into list of characters
        word = list(word)

        # Loop ends when the pointer meet at middle of the array
        while left_index < right_index:
            # Effectively reversing the characters
            word[left_index], word[right_index] = word[right_index], word[left_index]
            # Move pointers towards each other
            left_index += 1
            right_index -= 1

        # Join reverse list of characters back as a single string
        word = "".join(word)
        result.append(word)

    return " ".join(result)


def main() -> int:
    s_1 = "Let's take LeetCode contest"
    s_2 = "Mr Ding"

    for s in [s_1, s_2]:
        print(f"The input string {s_1} becomes {reverse_words(s)}")

    return 0


if __name__ == "__main__":
    main()
