## Palindrome

A palindrome is a word, phrase, number, or other sequence of characters that reads the same forward and backward (ignoring spaces, punctuation, and capitalization). 

### Time Complexity

The time complexity is $O(n)$ because the while loop iterations cost $O(1)$ each, and there can never be more than $O(n)$ iterations of the while loop. The pointers start at a distance of $n$ from each other and move closer by one step each iteration.

### Space Complexity

No matter how big the input is, we always only use two integer variables. Therefore, the space complexity is $O(1)$.
