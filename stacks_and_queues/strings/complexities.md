# Valid Parentheses

Given a string `s` containing characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. An input string is valid if:

* Open brackets must be closed by the same type of brackets
* Open brackets must be closed in the correct order
* Every close bracket has a corresponding open bracket of the same type

Return `True` if `s` is valid, `False` otherwise.

## Example

1. Input: s = "()", Output: True

2. Input: s = "()[]{}", Output: True

3. Input: s = "(]", Output: False

4. Input: s = "([)]", Output: False

5. Input: s = "{[]}", Output: True

## Explanation

### Valid Case

The string `s = "{[]}"` is valid because the brackets are closed in the correct order.

<center>

| Stack | Current Bracket | Action |
|-------|-----------------|--------|
| []    | {               | Push the bracket onto the stack |
| ["{"] | [               | Push the bracket onto the stack |
| ["{", "["] | ]           | - Check that this is a closing bracket `True` <br> - Check that the stack is not empty `True` <br> - Check that the current top of the stack is the corresponding opening bracket `[` <-> `]` <br> - Pop the opening bracket from the stack |
| ["{"] | }               | - Check that this is a closing bracket `True` <br> - Check that the stack is not empty `True` <br> - Check that the current top of the stack is the corresponding opening bracket `{` <-> `}` <br> - Pop the opening bracket from the stack |
| []    |                 | The stack is empty, all opening brackets have been closed in the correct order, return `True` |

</center>

### Invalid Case

The string `s = "([)]"` is invalid because the brackets are not closed in the correct order.

<center>

| Stack | Current Bracket | Action |
|-------|-----------------|--------|
| []    | (               | Push the bracket onto the stack |
| ["("] | [               | Push the bracket onto the stack |
| ["(", "["] | )           | - Check that this is a closing bracket `True` <br> - Check that the stack is not empty `True` <br> - Check that the current top of the stack is the corresponding opening bracket `[` <-> `]` <br> - The current bracket is not the corresponding closing bracket for the top of the stack, return `False` |

</center>

## Time Complexity

Given $n$ as the length of the input string $s$, we iterate through each character in the string; during each iteration, we perform the following operations:

* Look up the current character in a dictionary to determine if it is an opening bracket, costing $O(1)$ 

  - If the current character is an opening bracket, push it onto the stack, costing $O(1)$

  - If the current character is a closing bracket, more operations are performed:

    - Check that the stack is not empty, which is $O(1)$

    - Pop the opening bracket from the stack, costing $O(1)$

    - Look up the last open bracket in a dictionary to determine if it is the corresponding opening bracket to the current closing bracket, costing $O(1)$

In the worst case, we iterate through all $n$ characters in the input string $s$, performing $O(1)$ operations for each character. Therefore, the overall time complexity is $O(n)$.

## Space Complexity

In the worst case, i.e. all characters are opening brackets, we would push all $n$ characters onto the stack. Therefore, the space complexity is $O(n)$.

This is not considering the space complexity of the dictionary used to store the bracket mappings, which can be considered as $O(1)$ since the dictionary will only contain a constant number of key-value pairs.

---

# Remove All Adjacent Duplicates In String

Given a string `s` containing lowercase English letters, remove all adjacent duplicates from the string. 

## Explanation

Given `s = "abbaca"`, we can remove the adjacent duplicates as follows:

<center>

| Stack | Current Character | Action |
|-------|-------------------|--------|
| []    | a                 | Push the character onto the stack |
| ["a"] | b                 | Push the character onto the stack |
| ["a", "b"] | b             | The current character is the same as the top of the stack, pop the top of the stack |
| ["a"] | a                 | The current character is the same as the top of the stack, pop the top of the stack |
| []    | c                 | Push the character onto the stack |
| ["c"] | a                 | Push the character onto the stack |

</center>

After removing all adjacent duplicates, the resulting string is `s = "ca"`.

## Time Complexity

Given $n$ as the length of the input string $s$, we iterate through each character in the string; during each iteration, we perform the following operations:

* Check if the stack is empty and if the current character is the same as the top of the stack both in $O(1)$

  - If the current character is the same as the top of the stack, pop the top of the stack in $O(1)$

* If the current character is not the same as the top of the stack or the stack is empty, push the current character onto the stack in $O(1)$

### C++

In C++, we can directly use `std::string::push_back()` and `std::string::pop_back()` to simulate the stack operations. These operations are both unspecified but generally amortized $O(1)$ according to references [here](https://cplusplus.com/reference/string/string/push_back/) and [here](https://cplusplus.com/reference/string/string/pop_back/). Therefore, the overall time complexity is $O(n)$.

### Python

In Python, we also need to join the characters in the stack to form a string. The time complexity of this operation is $O(n)$. Therefore, the overall time complexity is $O(n + n) = O(2n) = O(n)$.

## Space Complexity

We use a stack (i.e., list in Python and string in C++) to store the characters. In the worst case, we would push all $n$ characters onto the stack. Therefore, the space complexity is $O(n)$.

---

# Backspace String Compare

Given two strings `s` and `t`, both containing lowercase English letters and the character '#', determine if the two strings are equal after applying the backspace characters.

A backspace character '#' removes the character before it, including itself. If there is no character before the backspace character, it has no effect.

## Explanation

Given `s = "ab#c"` and `t = "ad#c"`, we can apply the backspace characters as follows:

For string `s`:

<center>

| Stack | Current Character | Action |
|-------|-------------------|--------|
| []    | a                 | Push the character onto the stack |
| ["a"] | b                 | Push the character onto the stack |
| ["a", "b"] | #             | Pop the top of the stack |
| ["a"] | c                 | Push the character onto the stack |

</center>

After applying the backspace characters, the resulting string is `s = "ac"`.

For string `t`:

<center>

| Stack | Current Character | Action |
|-------|-------------------|--------|
| []    | a                 | Push the character onto the stack |
| ["a"] | d                 | Push the character onto the stack |
| ["a", "d"] | #             | Pop the top of the stack |
| ["a"] | c                 | Push the character onto the stack |

</center>

After applying the backspace characters, the resulting string is `t = "ac"`.

Since the resulting strings are equal, we return `True`.

## Time Complexity

### Building the Strings

Let $n$ and $m$ be the lengths of strings `s` and `t`, respectively. We iterate through each character in both strings, performing the following operations:

* Check if the stack is empty and if the current character is a backspace character, both in $O(1)$

  - If the current character is a backspace character and the stack is not empty, pop the top of the stack in $O(1)$

* If the stack is empty, the condition above will not be met, but we need to double check that the current character is not a backspace character before pushing it onto the stack in $O(1)$

The process of building the strings takes $O(n + m)$ time.

**Note**: Again, in Python, we need to join the characters in the stack to form a string. But the overall time complexity is still $O(n + m + n + m) = O(2n + 2m) = O(n + m)$.

### Comparing the Strings

The comparison of two strings of fixed lengths can be considered $O(1)$ if the lengths of the built strings are not the same. In the worst case, when the lengths of the built strings are the same, we need to compare each character in the strings, which takes $O(\text{min}(n, m))$. 

### Overall Time Complexity

Considering the time complexities of building the strings and comparing the resultant strings, the overall time complexity is $O(n + m + \text{min}(n, m))$. If $n = m$, the time complexity is $O(3n) = O(n)$.

## Space Complexity

We use a stack for each string to store the characters. In the worst case, we would push all $n$ and $m$ characters onto the stacks; that is, neither string contains any backspace characters. 

Therefore, the space complexity is $O(n + m)$. If $n = m$, the space complexity can be considered $O(2n)=O(n)$.
