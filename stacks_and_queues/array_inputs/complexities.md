# Validate Stack Sequences

Given two sequences `pushed` and `popped` with distinct values, return `True` if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack. 

## Explanation

### Valid Case

Consider the example:

* `pushed = [1, 2, 3, 4, 5]`

* `popped = [4, 5, 3, 2, 1]`

<center>

| Pushed & Popped | Stack | Popped Index & Value | Stack Not Empty & Stack[-1] == Popped Value | Stack After Pop | 
|--------|-------|----------------------|-----------------------------------------|------------------|
| push 1      | [1]   | 0: 4                 | True & False = False                                 | No Pop Operation |
| push 2      | [1, 2] | 0: 4                | True & False = False                                 | No Pop Operation |
| push 3      | [1, 2, 3] | 0: 4             | True & False = False                                 | No Pop Operation |
| push 4      | [1, 2, 3, 4] | 0: 4         | True & True = True                                  | [1, 2, 3]       |
| push 5      | [1, 2, 3, 5] | 1: 5         | True & True = True                                  | [1, 2, 3]       |
| pop 3      | [1, 2] | 2: 3                | True & True = True                                  | [1, 2]          |
| pop 2      | [1]   | 3: 2                 | True & True = True                                  | [1]             |
| pop 1      | []    | 4: 1                 | True & True = True                                  | []              |

</center>

### Invalid Case

Consider the example:

* `pushed = [1, 2, 3, 4, 5]`

* `popped = [4, 3, 5, 1, 2]`

<center>

| Pushed & Popped | Stack | Popped Index & Value | Stack Not Empty & Stack[-1] == Popped Value | Stack After Pop |
|--------|-------|----------------------|-----------------------------------------|------------------|
| push 1      | [1]   | 0: 4                 | True & False = False                                 | No Pop Operation |
| push 2      | [1, 2] | 0: 4                | True & False = False                                 | No Pop Operation |
| push 3      | [1, 2, 3] | 0: 4             | True & False = False                                 | No Pop Operation |
| push 4      | [1, 2, 3, 4] | 0: 4         | True & True = True                                  | [1, 2, 3]       |
| NA         | [1, 2, 3] | 1: 3                | True & True = True                                  | [1, 2]          |
| push 5      | [1, 2, 3, 5] | 2: 5         | True & True = True                                  | [1, 2]          |

</center>

Loop completes and `stack` is not empty. Hence, the sequences of `pushed` and `popped` are invalid.

## Time Complexity

Let $n$ be the length of the `pushed` and `popped` sequences.

We iterate through all elements of `pushed` and carry out the following operations:

1. Push the element to the stack, costing $O(1)$

2. Check if `stack` is not empty and `stack[-1]` is equal to the current element of `popped`, both of which cost $O(1)$; if the conditions are met:

    - Pop the top element of `stack`, costing $O(1)$

    - Increment the index of `popped`, also $O(1)$

The overall time complexity is $O(n)$.

## Space Complexity

The space complexity is $O(n)$, as we use a `stack` to carry out the push and pop operations. In the worst case, every element of `pushed` is pushed to the stack, and none are popped.
