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

Each day's index is pushed and popped from the stack at most once. In the worst-case scenario, such as when temperatures are strictly increasing (e.g., `[30, 35, 53, 62, 70, 90]`), every index from 0 to $n - 1$ is pushed and then popped.

Thus, the overall time complexity is $O(2n)$, which simplifies to $O(n)$.

## Space Complexity

Not considering the space required to store the output array, which is $O(n)$, the algorithm uses a stack to store the day indices. The stack's space complexity is $O(n)$, as it can store at most $n$ day indices. 

The worst case occurs when the temperatures are in decreasing order, and the stack stores all $n$ day indices. For example, given temperatures = `[80, 76, 75, 52, 43, 38, 32]`, the stack would store `[0, 1, 2, 3, 4, 5, 6]`.

---

# Sliding Window Maximum

Given an array of integers `nums` and a sliding window of size `k`, this function processes the array by sliding the window from the left to the right. At each position, the window contains `k` consecutive elements from `nums`. Find the maximum element in each window and return an array of these maximum values.

## Explanation

Given `nums = [1, 3, -1, -3, 5, 3, 6, 7]` and `k = 3`:

<center>

| Index | Deque    | Window     | Max | Output               | Action                                                                                                                                                                                                                                          |
|-------|----------|------------|-----|----------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 0     | [0]      | [1]        | NA  | NA                   | <ul><li>Deque is empty, push index 0 onto the deque.</li></ul>                                                                                                                                                                                                  |
| 1     | [1]      | [1, 3]     | NA  | NA                   | <ul><li>`3 > 1`: </li><ul><li>Pop index 0 from the deque.</li><li>Push index 1 onto the deque.</li></ul>                                                                                                                                                  |
| 2     | [1, 2]   | [1, 3, -1] | 3   | [3]                  | <ul><li>`-1 < 3`: </li><ul><li>Push index 2 onto the deque.</li><li>Window size reached (`2 >= 2`): </li><ul><li>Check if `num_deque[-1] - num_deque[0] == k` (i.e., `2 - 1 != 3`).</li><li>Push `nums[1] = 3` to output.</li></ul></ul></ul>                                           |
| 3     | [1, 2, 3]| [3, -1, -3]| 3   | [3, 3]               | <ul><li>`-3 < -1`: </li><ul><li>Push index 3 onto the deque.</li><li>Window size reached (`3 >= 2`): </li><ul><li>Check if `num_deque[-1] - num_deque[0] == k` (i.e., `3 - 1 != 3`).</li><li>Push `nums[1] = 3` to output.</li></ul></ul></ul>                                           |
| 4     | [4]      | [-1, -3, 5]| 5   | [3, 3, 5]            | <ul><li>`5 > -3`: </li><ul><li>Pop index 3 from the deque.</li><li>`5 > -1`: </li><ul><li>Pop index 2 from the deque.</li><li>`5 > 3`: </li><ul><li>Pop index 1 from the deque.</li><li>Push index 4 onto the deque.</li></ul></ul><li>Window size reached (`4 >= 2`): </li><ul><li>Check if `num_deque[-1] - num_deque[0] == k` (i.e., `4 - 4 != 3`).</li><li>Push `nums[4] = 5` to output.</li></ul></ul></ul> |
| 5     | [4, 5]   | [-3, 5, 3] | 5   | [3, 3, 5, 5]         | <ul><li>`3 < 5`: </li><ul><li>Push index 5 onto the deque.</li><li>Window size reached (`5 >= 2`): </li><ul><li>Check if `num_deque[-1] - num_deque[0] == k` (i.e., `5 - 4 != 3`).</li><li>Push `nums[4] = 5` to output.</li></ul></ul></ul>                                           |
| 6     | [6]      | [5, 3, 6]  | 6   | [3, 3, 5, 5, 6]      | <ul><li>`6 > 3`: </li><ul><li>Pop index 5 from the deque.</li><li>`6 > 5`: </li><ul><li>Pop index 4 from the deque.</li><li>Push index 6 onto the deque.</li></ul><li>Window size reached (`6 >= 2`): </li><ul><li>Check if `num_deque[-1] - num_deque[0] == k` (i.e., `6 - 6 != 3`).</li><li>Push `nums[6] = 6` to output.</li></ul></ul></ul> |
| 7     | [7]      | [3, 6, 7]  | 7   | [3, 3, 5, 5, 6, 7]   | <ul><li>`7 > 6`: </li><ul><li>Pop index 6 from the deque.</li><li>Push index 7 onto the deque.</li><li>Window size reached (`7 >= 2`): </li><ul><li>Check if `num_deque[-1] - num_deque[0] == k` (i.e., `7 - 7 != 3`).</li><li>Push `nums[7] = 7` to output.</li></ul></ul></ul> |

</center>

The output array is `[3, 3, 5, 5, 6, 7]`.

## Time Complexity

Given $n$ elements in the input array `nums`, the algorithm processes each element as follows:

1. **While Loop**: As long as the deque is not empty and the current element is greater than the element at the back of the deque:

   - Pop the back of the deque in $O(1)$ time.

2. **Push Operation**: Push the current index onto the deque in $O(1)$ time.

3. **Window Size Check**: Check if window size has been reached, i.e., `i > k - 1`, costing $O(1)$:

   -  Check if the difference between the front and back of the deque is equal to `k` in $O(1)$

      - If the difference is `k`, then the front of the deque is outside the window; pop it in $O(1)$.

   - Push the maximum element, i.e., `nums[deque[0]]`, to the output array in $O(1)$ time.

In the worst case, i.e. when the input array is **strictly increasing**, each element is pushed to the deque once, and before pushing a new element, the previous element in the deque is popped (since the new element breaks the non-increasing monotonicity).

   - Each index is pushed once and can be popped at most once. This means there are at most $n$ push operations and $n$ pop operations, leading to $O(2n) = O(n)$ time.

The maximum element for each window is determined by the front index of the deque. There are `n - k + 1` windows where the maximum needs to be output.

   - Each index `deque[0]` and `output.push_back()` operations take $O(1)$ time, and since there are $n - k + 1$ such operations, this part contributes $O(n - k + 1)$ to the complexity.

The total time complexity is therefore:

$$
\begin{aligned}
O(n) + O(n - k + 1) &= O(2n - k + 1) \\
&= O(n)
\end{aligned}
$$

## Space Complexity

In the worst case, the deque stores all indices from the last window, i.e., $åk$ indices. This happens when the input array is **monotonically non-increasing**, which means there are no pop operations except for those used to maintain the window size. The space complexity is therefore $O(k)$.

---

# Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

Given an array of integers `nums` and an integer `limit`, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to `limit`.


## Explanation

Given `nums = [1, 5, 6, 7, 8, 10, 6, 5, 6]` and `limit = 4`:

<center>

| Left | Right | Window          | Monotonic Increasing           | Monotonic Decreasing           | Action                                                                                     |
|------|-------|-----------------|--------------------------------|--------------------------------|--------------------------------------------------------------------------------------------|
| 0    | 0     | [1]             | [1]                            | [1]                            | - Added 1 to both deques. <br> - Updated window size to 1 (right - left + 1 = 0 - 0 + 1).  |
| 0    | 1     | [1, 5]          | [1, 5]                         | [5]                            | - Popped 1 from decreasing deque because 1 < 5.<br>- Added 5 to both deques.<br>- Updated window size to 2 (right - left + 1 = 1 - 0 + 1). |
| 1    | 2     | [5, 6]          | [5, 6]                         | [6]                            | - Popped 5 from decreasing deque because 5 < 6.<br>- Added 6 to both deques.<br>- Window size is invalid because 6 - 1 > 4.<br>  - Popped 1 from front of increasing deque because it's equal to the leftmost element.<br>- Moved left to 1. Window is now [5, 6].<br>- Updated window size to 2 (right - left + 1 = 2 - 1 + 1). |
| 1    | 3     | [5, 6, 7]       | [5, 6, 7]                      | [7]                            | - Popped 6 from decreasing deque because 6 < 7.<br>- Added 7 to both deques.<br>- Updated window size to 3 (right - left + 1 = 3 - 1 + 1). |
| 1    | 4     | [5, 6, 7, 8]    | [5, 6, 7, 8]                   | [8]                            | - Popped 7 from decreasing deque because 7 < 8.<br>- Added 8 to both deques.<br>- Updated window size to 4 (right - left + 1 = 4 - 1 + 1). |
| 2    | 5     | [6, 7, 8, 10]   | [6, 7, 8, 10]                  | [10]                           | - Popped 8 from decreasing deque because 8 < 10.<br>- Added 10 to both deques.<br>- Window size is invalid because 10 - 5 > 4.<br>  - Popped 5 from front of increasing deque because it's equal to the leftmost element.<br>- Moved left to 2. Window is now [6, 7, 8, 10].<br>- Updated window size to 4 (right - left + 1 = 5 - 2 + 1). |
| 2    | 6     | [6, 7, 8, 10, 6] | [6, 6]                         | [10, 6]                        | - Popped 10 from increasing deque because 10 > 6.<br>  - Popped 8 from increasing deque because 8 > 6.<br>  - Popped 7 from increasing deque because 7 > 6.<br>- Added 6 to both deques.<br>- Updated window size to 5 (right - left + 1 = 6 - 2 + 1). |
| 6    | 7     | [6, 5]          | [5]                            | [6, 5]                         | - Popped 6 from increasing deque because 6 > 5.<br>  - Popped 6 from increasing deque because 6 > 5.<br>- Added 5 to both deques.<br>- Window size is invalid because 10 - 5 > 4.<br>- Moved left to 3. Window is now [7, 8, 10, 6, 5].<br>- Window size is invalid because 10 - 5 > 4.<br>- Moved left to 4. Window is now [8, 10, 6, 5].<br>- Window size is invalid because 10 - 5 > 4.<br>- Moved left to 5. Window is now [10, 6, 5].<br>- Window size is invalid because 10 - 5 > 4.<br>  - Popped 10 from front of decreasing deque because it's equal to the leftmost element.<br>- Moved left to 6. Window is now [6, 5].<br>- Updated window size to 5 (right - left + 1 = 7 - 6 + 1). |
| 6    | 8     | [6, 5, 6]       | [5, 6]                         | [6, 6]                         | - Popped 5 from decreasing deque because 5 < 6.<br>- Added 6 to both deques.<br>- Updated window size to 5 (right - left + 1 = 8 - 6 + 1). |

</center>

The longest continuous subarray with an absolute difference less than or equal to 4 is `[7, 7, 8, 10, 6]` with a size of 5.

## Time Complexity

Let $n$ be the number of elements in the input array `nums`. The algorithm iterates through each index of the array and performs the following operations:

1. **First Two While Loops**: The first two while loops are used to maintain the monotonicity of the increasing and decreasing deques. They are mutually exclusive in that:

   - If the input array is **strictly increasing**, every element will be pushed and popped from the decreasing deque repeatedly while only being pushed to the increasing deque.

   - If the input array is **strictly decreasing**, every element will be pushed and popped from the increasing deque repeatedly while only being pushed to the decreasing deque.

   In the sense, each element is pushed and popped at most $O(3n)$ times during these while loops in the worst case, contributing $O(n)$ to the total time complexity.

2. **Window Size Check**: In the worst case, with `limit = 0` and the gaps between each element in the input array being greater than zero (e.g. `[1, 3, 5, 7, 9, 11]` or `[17, 12, 7, 2]`), the window becomes invalid after each element is added. 

   - All work done inside the third `while` loop (i.e., comparison of two integers, popping the front of the deques) can be considered $O(1)$.
   - For an input of size $n$, there would be $n - 1$ comparisons between each pair of elements, leading to $O(n - 1) = O(n)$ pop operations to either the increasing (if the input is strictly decreasing) or decreasing deque (if the input is strictly increasing).

With both parts combined, the total time complexity can be modeled as $O(3n) + O(n) = O(4n) = O(n)$.

## Space Complexity

In the worst case, in which the input array remains constant (e.g., `[12, 12, 12, 12, 12]`), all elements are pushed to both deques and no pop operations are carried out. The space complexity is therefore $O(n + n) = O(2n) = O(n)$.
