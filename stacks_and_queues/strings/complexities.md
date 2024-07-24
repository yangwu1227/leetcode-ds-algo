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
