# Daily Temperatures

Given an array of integers `temperatures` representing daily temperatures, return an array `output` where `output[i]` indicates the number of days after the `i`-th day that a warmer temperature occurs. If no such day exists, set `out[i]` to 0.

## Explanation

Given temperatures = `[73, 74, 75, 71, 69, 72, 76, 73]`:

<center>

| Day Index Stack | Output Array              | Current Day Index | Previous Day Index | Condition Check                                       | Action                                                       |
|:---------------:|:-------------------------:|:-----------------:|:------------------:|:---------------------------------------------------:|:------------------------------------------------------------:|
| []              | [0, 0, 0, 0, 0, 0, 0, 0]  | 0                 | -1                 | Stack is empty                                      | Initialize the stack and output array                        |
| [0]             | [0, 0, 0, 0, 0, 0, 0, 0]  | 1                 | 0                  | Temperature 74 > 73                                 | Pop stack (previous day index 0) and set `output[0] = 1`     |
| [1]             | [1, 0, 0, 0, 0, 0, 0, 0]  | 2                 | 1                  | Temperature 75 > 74                                 | Pop stack (previous day index 1) and set `output[1] = 1`     |
| [2]             | [1, 1, 0, 0, 0, 0, 0, 0]  | 3                 | -1                 | Temperature 71 <= 75                                | Push current day index 3 onto the stack                      |
| [2, 3]          | [1, 1, 0, 0, 0, 0, 0, 0]  | 4                 | -1                 | Temperature 69 <= 71                                | Push current day index 4 onto the stack                      |
| [2, 3, 4]       | [1, 1, 0, 0, 0, 0, 0, 0]  | 5                 | 4, 3               | Temperature 72 > 69, Temperature 72 > 71            | Pop stack (previous day index 4, 3) and update `output[4]` and `output[3]` |
| [2, 5]          | [1, 1, 0, 2, 1, 0, 0, 0]  | 6                 | 5, 2               | Temperature 76 > 72, Temperature 76 > 75            | Pop stack (previous day index 5, 2) and update `output[5]` and `output[2]` |
| [6]             | [1, 1, 4, 2, 1, 1, 0, 0]  | 7                 | -1                 | Temperature 73 <= 76                                | Push current day index 7 onto the stack                      |

</center>

The output array is `[1, 1, 4, 2, 1, 1, 0, 0]`.

## Time Complexity

Given $n$ days of temperatures, the algorithm processes each day as follows:

1. **While Loop**: As long as the stack is not empty and the current temperature is greater than the temperature at the top of the stack:

   - Pop the top of the stack and update the output array in $O(1)$ times.

2. **Push Operation**: If the current temperature is less than or equal to the temperature at the top of the stack, or after the stack becomes empty, we push the current day index onto the stack in $O(1)$ time.

Each day's index is pushed and popped from the stack at most once. In the worst-case scenario, such as when temperatures are in increasing order (e.g., `[30, 35, 53, 62, 70, 90]`), every index from 0 to $n - 1$ is pushed and then popped.

Thus, the overall time complexity is $O(2n)$, which simplifies to $O(n)$.

## Space Complexity

Not considering the space required to store the output array, which is $O(n)$, the algorithm uses a stack to store the day indices. The stack's space complexity is $O(n)$, as it can store at most $n$ day indices. 

The worst case occurs when the temperatures are in decreasing order, and the stack stores all $n$ day indices. For example, given temperatures = `[80, 76, 75, 52, 43, 38, 32]`, the stack would store `[0, 1, 2, 3, 4, 5, 6]`.
