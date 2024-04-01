from collections import deque

class Solution(object):
    """
    Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the 
    index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.

    Parameters
    ----------
    word : str
        A string constituting a word.
    ch : str
        A character.

    Returns
    -------
    str
        A string with specified segment reversed.
    """
    @staticmethod
    def reverse_prefix_list(word: str, ch: str) -> str:
        # O(n) convert string to a list of characters
        word = list(word)
        
        ch_index = -1
        for i in range(len(word)):
            # If found, store the index and break out of the loop
            if word[i] == ch:
                ch_index = i
                break
        # If no match found, return the original word
        if ch_index == -1:
            return "".join(word)
        
        left_index = 0
        right_index = ch_index
        
        while left_index < right_index:
            # Reverse by swapping the left and right elements
            word[left_index], word[right_index] = word[right_index], word[left_index]
            left_index += 1
            right_index -= 1
            
        # O(n) to join the list of characters back
        return "".join(word)
    
    @staticmethod
    def reverse_prefix_str(word: str, ch: str) -> str:
        # Use the find method to find the first occurrence of 'ch'
        ch_index = word.find(ch)
        if ch_index == -1:
            return word
        # First segment is reversed characters from 0 to ch_index + 1
        # Second segment contains the remaining characters in the same order
        return word[:ch_index + 1][::-1] + word[ch_index + 1:]


def main() -> int:
    
    word_1 = "abcdefd"
    ch_1 = "d"
    word_2 = "xyxzxe"
    ch_2 = "z"
    word_3 = "abcd"
    ch_3 = "z"
    
    solution = Solution()
    for word, ch in zip([word_1, word_2, word_3], [ch_1, ch_2, ch_3]):
        
        result_list = solution.reverse_prefix_list(word, ch)
        result_str = solution.reverse_prefix_str(word, ch)
        
        assert result_list == result_str
        
        print(f"String method: The input {word} with character {ch} -> {result_str}")
        print(f"Join method: The input {word} with character {ch} -> {result_list}\n")
    
    return 0

if __name__ == "__main__":
    
    main()
