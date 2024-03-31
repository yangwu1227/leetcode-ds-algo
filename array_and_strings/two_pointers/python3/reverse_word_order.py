from collections import deque

class Solution(object):
    """
    Given an input string s, reverse the order of the words. A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
    
    Parameters
    ----------
    s : str
        Input string
        
    Returns
    -------
    str
        The string with the words reversed
    """
    @staticmethod
    def reverse_word_order(s: str) -> str:
        # O(n) operation to strip leading and trailing white spaces
        s = s.strip()
        
        # O(n) operation to convert string to a list of words
        s = s.split(sep=None)
        
        left_index = 0
        right_index = len(s) - 1

        while left_index < right_index:
            s[left_index], s[right_index] = s[right_index], s[left_index]
            left_index += 1
            right_index -= 1
            
        # Another O(n) operation to join reversed words into a string
        return ' '.join(s)
    
    @staticmethod
    def reverse_word_order_deque(s: str) -> str:
        # For memory efficient appends from either side ~ O(1)
        result = deque(maxlen=len(s))
        
        # Start index to keep track of start of each word
        start_index = -1
        # Pointer that iterates through the entire string
        i = 0
        
        while i < len(s):
            # If not white space, we need to process
            if s[i] != " ":
                # First, mark the current index as the start
                start_index = i
                
                # This loop break only if we are at the end i == len(s)
                # Or, we encounter the next white space (i.e. end of word)
                while i < len(s) and s[i] != " ":
                    # Increment the pointer to move left
                    i += 1
                       
                # The slice start_index:i (non-inclusive) gives us the entirety of a word
                # Append the word to the container from the left
                result.appendleft(s[start_index:i])
                
                # Since we have a global += 1 below, we need to cancel it out so we don't skip pointers
                i -= 1

            # If white space (if block does not run), skip by incrementing i
            i += 1
                
        return " ".join(result)

def main() -> int:
    
    s_1 = "the sky is blue"
    s_2 = "  hello world  "
    s_3 = "a good   example"
    
    solution = Solution
    
    for s in [s_1, s_2, s_3]:
        
        result_1 = solution.reverse_word_order(s)
        result_2 = solution.reverse_word_order_deque(s)
        
        assert result_1 == result_2
        
        print(f'The input {s_1} becomes {result_1}')
        
    return 0

if __name__ == "__main__":
    
    main()
