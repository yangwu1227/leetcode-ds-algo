## Palindrome

A palindrome is a word, phrase, number, or other sequence of characters that reads the same forward and backward (ignoring spaces, punctuation, and capitalization). 

### Time Complexity

The time complexity is $O(n)$ because the while loop iterations cost $O(1)$ each, and there can never be more than $O(n)$ iterations of the while loop. The pointers start at a distance of $n$ from each other and move closer by one step each iteration.

### Space Complexity

No matter how big the input is, we always only use two integer variables. Therefore, the space complexity is $O(1)$.

---

## Sorted Two Sum

Given a sorted array of unique integers and a target integer, return true if there exists a pair of numbers that sum to target, false otherwise. This problem is similar to Two Sum. (In Two Sum, the input is not sorted).

The brute force solution would be to iterate over all pairs of integers. Each number in the array can be paired with another number, so this would result in a time complexity of $O\left(n^2\right)$, where $n$ is the length of the array. Because the array is sorted, we can use two pointers to improve to an $O(n)$ time complexity.

```python
nums = [1, 2, 4, 6, 8, 9, 14, 15]
target = 13
```

With two pointers, we start by looking at the first and last number. Their sum is $1+15=16$. Because $16>$ target, we need to make our current sum smaller. Therefore, we should move the right pointer. Now, we have $1+14=15$. Again, move the right pointer because the sum is too large. Now, $1+9=10$. Since the sum is too small, we need to make it bigger, which can be done by moving the left pointer. Then, $2+9=11<$ target, so move it again. Finally, $4+9=13=$ target.

The reason this algorithm works: because the numbers are sorted, moving the left pointer permanently **increases** the value the left pointer points to (nums [left] $=\mathrm{x}$). Similarly, moving the right pointer permanently **decreases** the value the right pointer points to (nums [right] $=y$ ). 

1. If we have $x+y>$ target, then we can never have a solution with $y$ because $x$ can only increase. So if a solution exists, we can only find it by decreasing $y$. 
2. If we have $x+y<$ target, then we can never have a solution with $x$ because $y$ can only decrease. So if a solution exists, we can only find it by increasing $x$.

### Time Complexity

The time complexity is $O(n)$ because the while loop iterations cost $O(1)$ each, and there can never be more than $O(n)$ iterations of the while loop. 

### Space Complexity

No matter how big the input is, we always only use two integer variables. Therefore, the space complexity is $O(1)$.
