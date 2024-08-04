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

---

# Asteroid Collision

Simulates the collision of asteroids based on their size and direction. Each asteroid moves at the same speed. If 
two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Asteroids moving in the same direction will never meet.

## Explanation

Consider the example `data = [10, 2, -5]`:

<center>

| Step | Action                | Current Asteroid | Stack State Before Action | Condition Check                               | Action Taken                               | Stack State After Action |
|------|-----------------------|------------------|---------------------------|-----------------------------------------------|--------------------------------------------|--------------------------|
| 1    | Start                 | 10               | []                        | Stack is empty                                | Append 10                                  | [10]                     |
| 2    | Start                 | 2                | [10]                      | 2 > 0                                         | Append 2                                   | [10, 2]                  |
| 3    | Start                 | -5               | [10, 2]                   | -5 < 0, 2 > 0, and stack is not empty.                 | Check collisions                           |                          |
| 3.1  | Collision Check       | -5               | [10, 2]                   | Top of stack 2, Current asteroid -5           | Top of stack is smaller                    | Pop 2                    | [10]                     |
| 3.2  | Collision Check       | -5               | [10]                      | Top of stack 10, Current asteroid -5          | Top of stack is larger                     | No action                | [10]                     |
| 3.3  | End Processing        | -5               | [10]                      | No more collisions to resolve                 | No action                                  | [10]                     |

</center>

1. **Step 1**: The first asteroid `10` is processed. Since the stack is empty, `10` is appended to the stack.

   - **Condition Check**: Stack is empty.

   - **Action Taken**: Append `10`.

   - **Stack State After Action**: `[10]`.

2. **Step 2**: The second asteroid `2` is processed. Since `2` is moving to the right (positive value), it is appended to the stack.

   - **Condition Check**: `2 > 0`.

   - **Action Taken**: Append `2`.

   - **Stack State After Action**: `[10, 2]`.

3. **Step 3**: The third asteroid `-5` is processed. It starts checking for collisions since it is moving to the left and the stack is not empty.

   - **Condition Check**: `-5 < 0`, `2 > 0`, and stack is not empty.

   - **Action Taken**: Begin collision check.

    * **Step 3.1**: Collision check begins. The top of the stack is `2` which is smaller than `-5`.

        - **Condition Check**: Top of stack `2`, Current asteroid `-5`.

        - **Action Taken**: Pop `2`.

        - **Stack State After Action**: `[10]`.

    * **Step 3.2**: Continue collision check. The top of the stack is now `10` which is larger than `-5`.

        - **Condition Check**: Top of stack `10`, Current asteroid `-5`.

        - **Action Taken**: No action, as `10` is larger.

        - **Stack State After Action**: `[10]`.

    * **Step 3.3**: End processing for `-5` as there are no more collisions to resolve.

        - **Condition Check**: No more collisions.

        - **Action Taken**: No action.

        - **Stack State After Action**: `[10]`.

The final state of the asteroids after all collisions is `[10]`.

## Time Complexity

Let $n$ be the length of the `data` input, we iterate through all elements of `data` and carry out the following operations:

* Condition checks:

    - If the stack is empty, costing $O(1)$

    - Or if the current asteroid is moving to the right, costing $O(1)$

    - Or if the top of the stack is moving to the left, costing $O(1)$

    As long as one of the conditions is met, we push the current asteroid to the stack in $O(1)$

* If the complement of the above conditions is met, i.e.,

    - The stack is not empty

    - The current asteroid is moving to the left

    - The top of the stack is moving to the right

    We begin the collision checks:

    * Compte the absolute values of the top of the stack and the current asteroid, costing $O(1)$

    * If the top of the stack is smaller or equal to the current asteroid, we pop the top of the stack, costing $O(1)$

    We continue the popping operations until either the stack is empty or current asteroid and top of the stack are moving in the same direction.

Considering all steps, the overall time complexity is amortized $O(n)$. 

Even though we have a nested `while` loop inside the `for` loop, each element can only be added and removed from the stack once. Therefore, the total number of push and pop operations is bounded by $2n$, which results in an amortized $O(n)$ time complexity.

## Space Complexity

The space complexity is $O(n)$, as we use a stack to store the asteroids. In the worst case, all asteroids are moving in the same direction, and none collide.
