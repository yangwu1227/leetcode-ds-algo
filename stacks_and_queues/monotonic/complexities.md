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

---

# Next Greater Element I 


Given two distinct integer arrays `nums_1` and `nums_2` where `nums_1` is a subset of `nums_2`, find the array `output` such that for each element `nums_1[i]`, `output[i]` contains the next greater element of `nums_1[i]` in `nums_2`. If no such element exists, `output[i]` will be -1.

## Explanation

The algorithm uses a stack to store the elements in increasing order and a hash map to store the next greater element for each element in `nums_2`.

<center>
    <img src="diagrams/next_greater_element.gif">
</center>

<br>

Given `nums_1 = [5, 7, 1]` and `nums_2 = [2, 3, 5, 1, 0, 7, 3]`:

* Hash map: `{2: 3, 3: 5, 0: 7, 1: 7, 5: 7, 3: -1, 7: -1}`

The output array is `[7, -1, 7]`.

## Time Complexity

Let $n$ be the number of elements in `nums_2` and $m$ be the number of elements in `nums_1`. The algorithm carries out the following operations:

1. Iterate over the elements in `nums_2`:

   - While the stack is not empty and the current element is greater than the element at the top of the stack, pop the top element and update the hash map in both in $O(1)$ time. 

   - Push the current element onto the stack in $O(1)$ time.

   Each element can be pushed and popped *at most once*, leading to $O(2n) = $O(n)$ time complexity.

2. Iterate over the elements in `nums_1`:

   - Lookup the next greater element for each element in $O(1)$ time.

The time complexity of the algorithm is $O(n + m)$.

## Space Complexity

In the worst case, where `nums_2` is strictly decreasing, the stack stores all elements from `nums_2` since there would be no pop operations. The space complexity of the stack is $O(n)$. Adding the space required for the hash map, which is $O(n)$, the total space complexity is $O(2n) = O(n)$.

If we also consider the space required to store the output array, which is $O(m)$, the total space complexity becomes $O(n + m)$.

---

# Online Stock Span

Design an algorithm to calculate the span of a stock's price for the current day based on daily price quotes. The span is the number of consecutive days (including today) where the price was less than or equal to the current price.

**Example:**
- Prices: `[7, 2, 1, 2]`, Today's price: `2` → Span: `4`
- Prices: `[7, 34, 1, 2]`, Today's price: `8` → Span: `3`

**Implement the `StockSpanner` class:**
- `StockSpanner()`: Initializes the class instance.
- `int next(int price)`: Returns the span for today's price.

## Explanation

We use a montonic decreasing stack to store pair of `(price, span)` for each day. The stack is used to calculate the span for the current day based on the previous days' prices.

Given the example `[100, 80, 60, 70, 60, 75, 85]`:

<center>

| Step | Current Price | Action | Stack State | Span |
|------|---------------|--------|-------------|------|
| 1    | 100           | Initialized span to 1 | `[]` |   |
| 2    |               | Append (100, 1) to the stack | `[(100, 1)]` | 1 |
| 3    | 80            | Initialized span to 1 | `[(100, 1)]` |   |
| 4    |               | Append (80, 1) to the stack | `[(100, 1), (80, 1)]` | 1 |
| 5    | 60            | Initialized span to 1 | `[(100, 1), (80, 1)]` |   |
| 6    |               | Append (60, 1) to the stack | `[(100, 1), (80, 1), (60, 1)]` | 1 |
| 7    | 70            | Initialized span to 1 | `[(100, 1), (80, 1), (60, 1)]` |   |
| 8    |               | The pair (60, 1) will be popped since its price (60) is lower than 70 | `[(100, 1), (80, 1)]` |   |
| 9    |               | Append (70, 2) to the stack | `[(100, 1), (80, 1), (70, 2)]` | 2 |
| 10   | 60            | Initialized span to 1 | `[(100, 1), (80, 1), (70, 2)]` |   |
| 11   |               | Append (60, 1) to the stack | `[(100, 1), (80, 1), (70, 2), (60, 1)]` | 1 |
| 12   | 75            | Initialized span to 1 | `[(100, 1), (80, 1), (70, 2), (60, 1)]` |   |
| 13   |               | The pair (60, 1) will be popped since its price (60) is lower than 75 | `[(100, 1), (80, 1), (70, 2)]` |   |
| 14   |               | The pair (70, 2) will be popped since its price (70) is lower than 75 | `[(100, 1), (80, 1)]` |   |
| 15   |               | Append (75, 4) to the stack | `[(100, 1), (80, 1), (75, 4)]` | 4 |
| 16   | 85            | Initialized span to 1 | `[(100, 1), (80, 1), (75, 4)]` |   |
| 17   |               | The pair (75, 4) will be popped since its price (75) is lower than 85 | `[(100, 1), (80, 1)]` |   |
| 18   |               | The pair (80, 1) will be popped since its price (80) is lower than 85 | `[(100, 1)]` |   |
| 19   |               | Append (85, 6) to the stack | `[(100, 1), (85, 6)]` | 6 |

</center>

The spans for the given prices are `[1, 1, 1, 2, 1, 4, 6]`.

## Time Complexity

During each call to the `next` function, the algorithm performs the following operations:

* Initialize the span to 1 in $O(1)$ time

* `While` the stack is non-empty and the current price is greater than the price at the top of the stack:

  - Pop the top of the stack in $O(1)$ time and use the stored span on that day to update the current day's span.

* Push the current price and span onto the stack in $O(1)$ time.

On any given day, assuming that the stack has $n$ pairs of `(price, span)` accumulated from previous days, the algorithm performs at most $O(n)$ pop operations if the current price is greater than all previously stored prices. 

For example, if the prices are as follows `[100, 80, 60, 40, 30, 13, 102]`, the stack will contain the following pairs right before the last price is processed: `[(100, 1), (80, 1), (60, 1), (40, 1), (30, 1), (13, 1)]`. 

When the price `102` is processed, the stack will be emptied, leading to $O(n)$ pop operations.

Therefore, the worst case time complexity is $O(n)$ for the `next` function.

## Space Complexity

Considering the space required to store pairs of `(price, span)` in the stack, the space complexity is $O(n)$, where $n$ is the number of days for which the span is calculated. This occurs if the prics are strictly decreasing during the entire period of calculation.

For instance, if the prices are `[100, 80, 60, 40, 30, 13, 10]`, all pairs will be stored in the stack.

---

# Final Prices With a Special Discount in a Shop

The integer array `prices` is such that `prices[i]` represents the price of the ith item in a shop

For each item, if a later item has a price less than or equal to the current item's price, a discount is applied. The discount is equal to the price of the first such item found. If no such item exists, no discount is applied.

Return an integer array `output`, where `output[i]` is the final price after applying the discount, if applicable.

## Explanation

Consider the example `prices = [8, 4, 6, 2, 3]`:

<center>

| Index | Stack | Current Price | Condition Check | Action | Prices |
|-------|-------|---------------|-----------------|--------|------------------------|
| 0     | []    | 8             | -               | Push index 0 onto the stack | [8, 4, 6, 2, 3]        |
| 1     | [0]   | 4             | 4 < 8           | - Pop index 0 from the stack and apply discount <br> - Push index 1 onto the stack | [8 - 4 = 4, 4, 6, 2, 3]        |
| 2     | [1]   | 6             | 6 > 4           | - Push index 2 onto the stack | [4, 4, 6, 2, 3]        |
| 3     | [1, 2]| 2             | 2 < 6 and 2 < 4          | - Pop index 2 from the stack and apply discount <br> - Pop index 1 from the stack and apply discount <br> - Push index 3 onto the stack | [4, 4 - 2 = 2, 6 - 2 = 4, 2, 3]        |
| 4     | [3]   | 3             | 3 > 2           | - Push index 4 onto the stack | [4, 2, 4, 2, 3]        |
| NA   | [3, 4]| -             | -               | NA | [4, 2, 4, 2, 3]        |

</center>

The final prices after applying discounts are `[4, 2, 4, 2, 3]`.

## Time Complexity

Given $n$ prices in the input array `prices`, the algorithm carries out the following operations for each price:

1. `While` the stack is not empty and the current price is less than the price at the top of the stack (i.e., a discount can be applied):

   - Pop the top of the stack and apply the discount both in $O(1)$ time.

2. Push the current price onto the stack in $O(1)$ time.

When the input prices are strictly non-increasing, every index is pushed and popped from the stack except for the last index. This results in $O(n + n - 1) = O(2n - 1) = O(n)$ time complexity.

## Space Complexity

In the worst case, i.e., when the input prices are strictly increasing, every index will be pushed onto the stack and no pop operations will be performed. The space complexity of the stack is therefore $O(n)$.

---

# Number of Visible People in a Queue

Given `n` people in a queue numbered from `0` to `n-1`, each with a distinct height in the array `heights`, where `heights[i]` is the height of the `i-th` person:

A person `i` can see person `j` to their right if `i < j` and `min(heights[i], heights[j]) > max(heights[i + 1], heights[i + 2], ..., heights[j - 1])`.

Return an array `output` of length `n` where `output[i]` is the number of people the `i-th` person can see to their right.

## Explanation

Consider `heights = [9, 10, 7, 2, 12, 13, 17]`:

<center>

| Person | Height | Initial Stack State  | Top of Stack Comparison                                                                                 | Action                                                                                                          | Final Visible Count | Stack After Processing |
|--------|--------|----------------------|-----------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------|---------------------|------------------------|
| 6      | 17     | []                   | N/A                                                                                                       | - The only visible person to person at index 6 is themselves. <br> - Push person with height 17 to the top of the stack. | 0                   | [17]                   |
| 5      | 13     | [17]                 | Person at index 5 with height 13 is shorter than top of the stack person with height 17; no pop operations | - The only visible person to person at index 5 is the person at index 6 with height 17. <br> - Push person with height 13 to the top of the stack. | 1                   | [17, 13]               |
| 4      | 12     | [17, 13]             | Person at index 4 with height 12 is shorter than top of the stack person with height 13; no pop operations | - The only visible person to person at index 4 is the person at index 5 with height 13. <br> - Push person with height 12 to the top of the stack. | 1                   | [17, 13, 12]           |
| 3      | 2      | [17, 13, 12]         | Person at index 3 with height 2 is shorter than top of the stack person with height 12; no pop operations  | - The only visible person to person at index 3 is the person at index 4 with height 12. <br> - Push person with height 2 to the top of the stack. | 1                   | [17, 13, 12, 2]        |
| 2      | 7      | [17, 13, 12, 2]      | Person at index 2 with height 7 is taller than top of the stack person with height 2; pop person with height 2 | - The second visible person to person at index 2 is the person at index 4 with height 12. <br> - Push person with height 7 to the top of the stack. | 2                   | [17, 13, 12, 7]        |
| 1      | 10     | [17, 13, 12, 7]      | Person at index 1 with height 10 is taller than top of the stack person with height 7; pop person with height 7 | - The second visible person to person at index 1 is the person at index 4 with height 12. <br> - Push person with height 10 to the top of the stack. | 2                   | [17, 13, 12, 10]       |
| 0      | 9      | [17, 13, 12, 10]     | Person at index 0 with height 9 is shorter than top of the stack person with height 10; no pop operations | - The only visible person to person at index 0 is the person at index 1 with height 10. <br> - Push person with height 9 to the top of the stack. | 1                   | [17, 13, 12, 10, 9]    |

</center>

## Time Complexity

Given $n$ people in the queue, the algorithm processes each person from left to right. For each person, the algorithm performs the following operations:

* Initialize the visible count to 0 in $O(1)$ time.

* `While` the stack is not empty and the current person is taller than the person at the top of the stack:

  - Increment the visible count of the current person in $O(1)$ time.
  - Pop the top of the stack in $O(1)$ time because this person is seen by the current person now.

* Check if the stack is non-empty, and if so, increment the visible count of the current person in $O(1)$ time; this accounts for the fact that, even if the current person is shorter than the top of the stack, this person is still the last visible person to the current person.

* Update the output array with the visible count of the current person in $O(1)$ time.

* Push the current person onto the stack in $O(1)$ time.

In the worst case, such that the heights are strictly decreasing, there would be $n$ push operations and $n - 1$ pop operations (i.e., the first person is pushed but never popped). Therefore, the total amount of work done inside the `for` loop is proportional to $O(2n - 1) = O(n)$.

## Space Complexity

In the worst case, such that the heights are strictly increasing, the stack would store all $n$ heights as there would be no pop operations. The space complexity of the stack is therefore $O(n)$.

---

# Sum of Subarray Minimums

Given an array of integers `x`, find the sum of the minimum elements of each subarray of `x`. Since the answer may be large, return the answer modulo $10^9 + 7$.

## Explanation

Given `x = [11, 81, 94, 43, 3]`:

### Left Span Calculation

The left minimum span of each element is calculated by finding the distance to the previous smaller element to the left of the current element. In other words, it represents the number of subarrays that end with the current element and have the current element as the minimum.

<center>

| Element | Index | Stack Before | Condition | Stack After | Left Span Calculation | Left Span Value |
|---------|-------|--------------|-----------|-------------|-----------------------|-----------------|
| 11      | 0     | []           | -         | [0]         | `left_spans[0] = 0 + 1` since stack is empty at this point | 1               |
| 81      | 1     | [0]          | 11 >= 81 is `False`  | [0, 1]      | `left_spans[1] = 1 - 0` | 1               |
| 94      | 2     | [0, 1]       | 81 >= 94 is `False`  | [0, 1, 2]   | `left_spans[2] = 2 - 1` | 1               |
| 43      | 3     | [0, 1, 2]    | 94 >= 43 and 81 >= 43 are both `True` so pop index 2 and 1 | [0, 3]      | `left_spans[3] = 3 - 0` | 3               |
| 3       | 4     | [0, 3]       | 43 >= 3 and 11 >= 3 are both `True` so pop index 3 and 0   | [4]         | `left_spans[4] = 4 + 1` since stack is empty at this point | 5           |

</center>

### Right Span Calculation

Similarly, the right minimum span of each element is calculated by finding the distance to the next smaller element to the right of the current element. This span represents the number of subarrays that start with the current element and have the current element as the minimum.

<center>

| Element | Index | Stack Before | Condition          | Stack After | Right Span Calculation | Right Span Value |
|---------|-------|--------------|--------------------|-------------|------------------------|------------------|
| 3       | 4     | []           | -                  | [4]         | `right_spans[4] = 5 - 4` since the stack is empty at this point | 1               |
| 43      | 3     | [4]          | 3 > 43 is `False`             | [4, 3]      | `right_spans[3] = 4 - 3` | 1               |
| 94      | 2     | [4, 3]       | 43 > 94 is `False`            | [4, 3, 2]   | `right_spans[2] = 3 - 2` | 1               |
| 81      | 1     | [4, 3, 2]    | 94 > 81 is `True`            | [4, 3, 1]   | `right_spans[1] = 3 - 1` | 2               |
| 11      | 0     | [4, 3, 1]    | 81 > 11 and 43 > 11 are both `True` so pop index 1 and 3   | [4, 0]      | `right_spans[0] = 4 - 0` | 4               |

</center>

### Final Contribution and Output Calculation

The contribution of each element to the final output is calculated as the product of the element, its left span, and its right span. The cumulative output is updated after each element is processed.

$$
\begin{aligned}
\text{Contribution of element x[i] to the minimum sum} &= \text{x[i]} \times \text{left spans[i]} \times \text{right spans[i]} 
\end{aligned}
$$

| Element | Index | Left Span | Right Span | Contribution Formula | Contribution Value | Cumulative Output |
|---------|-------|-----------|------------|----------------------|--------------------|-------------------|
| 11      | 0     | 1         | 4          | `11 * 1 * 4`         | 44                 | 44                |
| 81      | 1     | 1         | 2          | `81 * 1 * 2`         | 162                | 206               |
| 94      | 2     | 1         | 1          | `94 * 1 * 1`         | 94                 | 300               |
| 43      | 3     | 3         | 1          | `43 * 3 * 1`         | 129                | 429               |
| 3       | 4     | 5         | 1          | `3 * 5 * 1`          | 15                 | 444               |

</center>

The sum of the minimum elements of each subarray of `x` is `444`.

### Condition Checks for Left and Right Spans

To calculate the left and right spans of an element, the following conditions are used:

- **Left Span:** `x[stack[-1]] >= x[i]` — This ensures the top of the stack is always the first element to the left that is less than the current element `x[i]`.
- **Right Span:** `x[stack[-1]] > x[i]` — This ensures the top of the stack is always the first element to the right that is less than or equal to `x[i]`.

This approach avoids double counting by ensuring that subarray intervals are unique for each element.

### Example with Array `x = [1, 7, 3, 9, 4, 3, 0]`

#### Double Counting Issue

Consider the element `3` at index `2`:

- **Left Span:** The previous smaller element is at index `0` because `1 < 3`.
- **Right Span:** The next smaller element is at index `6` because `0 < 3`.

If both checks use "less than," the subarray where `3` is the minimum is incorrectly calculated as `x[0:-1]`:

```
[1, 7, 3, 9, 4, 3, 0]
 *     ^           *
```

For the element `3` at index `5`:

- **Left Span:** The previous smaller element is again at index `0` because `1 < 3`.
- **Right Span:** The next smaller element is at index `6` because `0 < 3`.

This results in the same subarray `x[0:6]`:

```
[1, 7, 3, 9, 4, 3, 0]
 *              ^  *
```

Therefore, we would be double counting the subarray where `3` is the minimum.

#### Avoiding Double Counting

To avoid double counting, use "less than" for the left span (i.e., pop if the top of the stack is $>= x[i]$) and "less than or equal to" for the right span (i.e., pop if the top of the stack is $> x[i]$).

For the element `3` at index `2`:

- **Left Span:** The previous smaller element is at index `0`.
- **Right Span:** The next smaller element is at index `5` because `3 <= 3`.

The correct subarray where the first `3` is the minimum is `x[0:5]`:

```
[1, 7, 3, 9, 4, 3, 0]
 *     ^        *   
```

For the element `3` at index `5`:

- **Left Span:** The previous smaller element is at index `0`.
- **Right Span:** The next smaller element is at index `6` because `0 <= 3`.

The subarray where the second `3` is the minimum is `x[0:6]`:

```
[1, 7, 3, 9, 4, 3, 0]
 *              ^  *
```

Using these conditions ensures each subarray interval is unique and accurately represents where each element is the minimum.

## Time Complexity

The time complexity of the left and right minimum span calculations are $O(n)$, where $n$ is the number of elements in the input array `x`. 

The time complexity of the final contribution and output calculation is also $O(n)$.

The total time complexity of the algorithm is therefore $O(n)$.

## Space Complexity

The following data structures are used in the algorithm:

* Two arrays of size $n$ to store the left and right minimum spans, respectively, costing $O(n)$ space.

* A deque to store the indices of the elements in the input array `x`. In the worst case, the deque stores all indices from the input array during either the left or right span calculations. This happens when the input array is strictly increasing or decreasing. 

   - For example, if the input array is `[1, 2, 3, 4, 5]`, the deque after the left span calculation will contain all indices from the input array `[0, 1, 2, 3, 4]`.

   - If the input array is `[5, 4, 3, 2, 1]`, the deque after the left span calculation will contain all indices from the input array `[4, 3, 2, 1, 0]`.

Therefore, the overall space complexity of the algorithm is therefore $O(n)$.

---

# Sum of Subarray Ranges

Given an integer array `nums`, find the sum of all subarray ranges. A subarray range is defined as the difference bewteen the maximum and minimum elements in a subarray.

## Explanation

Consider the example `nums = [4, -2, -3, 4, 1]` with $k$ continuous subarrays, the sum of all subarray ranges can be calculated as follows:

$$
\begin{aligned}
\sum_{k} \text{subarray range} &= \sum_{k} (\text{max value of kth subarray} - \text{min of kth subarray}) \\
&= \sum_{k} \text{max value of kth subarray} - \sum_{k} \text{min of kth subarray}
\end{aligned}
$$

The sum of all subarray ranges is the difference between the sum of the differences between the maximum and minimum values of all subarrays.

Using the linearity of the summations operator, we can calculate the sum of the maximum and minimum values of all subarrays separately before taking the difference between the two sums.

### Minimum Span Calculation

The minimum span of each element is the number of continuous subarrays that has the current element as the minimum. 

$$
\begin{aligned}
\sum_{k} \text{min of kth subarray} &= \sum_{i = 1}^{n} \text{min span of element i} \times \text{element i}
\end{aligned}
$$

where $n$ is the number of elements in the input array `nums`. In words, this means that the sum of minimum values of all $k$ subarrays is the sum of the products between each element and the number of times it is the minimum value of a unique subarray.

We can use a monotonic increasing stack to calculate the minimum span of each element, using it update the sum of the minimum values of all subarrays. Each time a index needs to be popped to maintain the monotonic increasing property, the number of subarrays that end with the current element and have the popped element as the minimum is calculated.

Define the following variables:

* `i` is the index of the element at the top of the stack

* `right` is the current index, whose corresponding element is less than the element at the top of the stack

* `left` is the index of the element that is the previous smaller element to the element at the top of the stack

* `(i - left)` is the number of possible starting positions of unique subarrays with element $i$ as the minimum

* `(right - i)` is the number of possible ending positions of unique subarrays with element $i$ as the minimum

Therefore, the number of continous subarrays that has element $i$ as the minimum is `(i - left)` $\times$ `(right - i)` using the multiplication principle of counting:

$$
\begin{aligned}
\text{min span of element i} &= (i - left) \times (right - i)
\end{aligned}
$$

<center>

| Iteration | Details | Stack | Condition | Equation | Output |
|-----------|---------|-------|-----------|----------|--------|
| **Initialization** | Initialized output to 0 | - Indices: `[]` <br> - Elements: `[]` |  |  | 0 |
| **Processing index 0** | nums[0] = 4 | - Indices: `[]` <br> - Elements: `[]`  | Stack is non-empty? False |  | 0 |
| &nbsp;&nbsp;&nbsp;&nbsp;**Push to stack** | | - Indices: `[0]` <br> - Elements: `[4]` |  |  | 0 |
| **Processing index 1** | nums[1] = -2 | - Indices: `[0]` <br> - Elements: `[4]` | Stack is non-empty? True and (top of stack: 4) >= (current element: -2)? True |  | 0 |
| &nbsp;&nbsp;&nbsp;&nbsp;**While Loop** | Popping index 0, which corresponds to 4 | - Indices: `[]` <br> - Elements: `[]` |  | `output -= 4 * (0 - -1) * (1 - 0)` | -4 |
| &nbsp;&nbsp;&nbsp;&nbsp;**Push to stack** | | - Indices: `[1]` <br> - Elements: `[-2]` |  |  | -4 |
| **Processing index 2** | nums[2] = -3 | - Indices: `[1]` <br> - Elements: `[-2]` | Stack is non-empty? True and (top of stack: -2) >= (current element: -3)? True |  | -4 |
| &nbsp;&nbsp;&nbsp;&nbsp;**While Loop** | Popping index 1, which corresponds to -2 | - Indices: `[]` <br> - Elements: `[]` |  | `output -= -2 * (1 - -1) * (2 - 1)` | 0 |
| &nbsp;&nbsp;&nbsp;&nbsp;**Push to stack** | | - Indices: `[2]` <br> - Elements: `[-3]` |  |  | 0 |
| **Processing index 3** | nums[3] = 4 | - Indices: `[2]` <br> - Elements: `[-3]` | Stack is non-empty? True and (top of stack: -3) >= (current element: 4)? False |  | 0 |
| &nbsp;&nbsp;&nbsp;&nbsp;**Push to stack** | | - Indices: `[2, 3]` <br> - Elements: `[-3, 4]` |  |  | 0 |
| **Processing index 4** | nums[4] = 1 | - Indices: `[2, 3]` <br> - Elements: `[-3, 4]` | Stack is non-empty? True and (top of stack: 4) >= (current element: 1)? True |  | 0 |
| &nbsp;&nbsp;&nbsp;&nbsp;**While Loop** | Popping index 3, which corresponds to 4 | - Indices: `[2]` <br> - Elements: `[-3]` |  | `output -= 4 * (3 - 2) * (4 - 3)` | -4 |
| &nbsp;&nbsp;&nbsp;&nbsp;**Push to stack** | | - Indices: `[2, 4]` <br> - Elements: `[-3, 1]` |  |  | -4 |
| **Processing index 5** | end of array | - Indices: `[2, 4]` <br> - Elements: `[-3, 1]` | Stack is non-empty? True and end of array? True |  | -4 |
| &nbsp;&nbsp;&nbsp;&nbsp;**While Loop** | Popping index 4, which corresponds to 1 | - Indices: `[2]` <br> - Elements: `[-3]` |  | `output -= 1 * (4 - 2) * (5 - 4)` | -6 |
| &nbsp;&nbsp;&nbsp;&nbsp;**While Loop** | Popping index 2, which corresponds to -3 | - Indices: `[]` <br> - Elements: `[]` |  | `output -= -3 * (2 - -1) * (5 - 2)` | 21 |
| &nbsp;&nbsp;&nbsp;&nbsp;**Push to stack** | | - Indices: `[5]` <br> - Elements: `[NA]` (Dummy index 5) |  |  | 21 |

</center>

### Maximum Span Calculation

Similarly, the maximum span of each element is the number of continuous subarrays that has the current element as the maximum.

$$
\begin{aligned}
\sum_{k} \text{max of kth subarray} &= \sum_{i = 1}^{n} \text{max span of element i} \times \text{element i}
\end{aligned}
$$

In words, this means that the sum of maximum values of all $k$ subarrays is the sum of the products between each element and the number of times it is the maximum value of a unique subarray. Given the same set of variables:

* `i` is the index of the element at the top of the stack

* `right` is the current index, whose corresponding element is greater than the element at the top of the stack

* `left` is the index of the element that is the previous greater element to the element at the top of the stack

$$
\begin{aligned}
\text{max span of element i} &= (i - left) \times (right - i)
\end{aligned}
$$

<center>

| Iteration | Details | Stack | Condition | Equation | Output |
|-----------|---------|-------|-----------|----------|--------|
| **Initialization** | Initialized output to 21 | - Indices: `[]` <br> - Elements: `[]` |  |  | 21 |
| **Processing index 0** | nums[0] = 4 | - Indices: `[]` <br> - Elements: `[]` | Stack is non-empty? False |  | 21 |
| &nbsp;&nbsp;&nbsp;&nbsp;**Push to stack** | | - Indices: `[0]` <br> - Elements: `[4]` |  |  | 21 |
| **Processing index 1** | nums[1] = -2 | - Indices: `[0]` <br> - Elements: `[4]` | Stack is non-empty? True and (top of stack: 4) <= (current element: -2)? False |  | 21 |
| &nbsp;&nbsp;&nbsp;&nbsp;**Push to stack** | | - Indices: `[0, 1]` <br> - Elements: `[4, -2]` |  |  | 21 |
| **Processing index 2** | nums[2] = -3 | - Indices: `[0, 1]` <br> - Elements: `[4, -2]` | Stack is non-empty? True and (top of stack: -2) <= (current element: -3)? False |  | 21 |
| &nbsp;&nbsp;&nbsp;&nbsp;**Push to stack** | | - Indices: `[0, 1, 2]` <br> - Elements: `[4, -2, -3]` |  |  | 21 |
| **Processing index 3** | nums[3] = 4 | - Indices: `[0, 1, 2]` <br> - Elements: `[4, -2, -3]` | Stack is non-empty? True and (top of stack: -3) <= (current element: 4)? True |  | 21 |
| &nbsp;&nbsp;&nbsp;&nbsp;**While Loop** | Popping index 2 since (top of stack: -3) <= (current element: 4) | - Indices: `[0, 1]` <br> - Elements: `[4, -2]` |  | `output += -3 * (2 - 1) * (3 - 2)` | 18 |
| &nbsp;&nbsp;&nbsp;&nbsp;**While Loop** | Popping index 1 since (top of stack: -2) <= (current element: 4) | - Indices: `[0]` <br> - Elements: `[4]` |  | `output += -2 * (1 - 0) * (3 - 1)` | 14 |
| &nbsp;&nbsp;&nbsp;&nbsp;**While Loop** | Popping index 0 since (top of stack: 4) <= (current element: 4) | - Indices: `[]` <br> - Elements: `[]` |  | `output += 4 * (0 - -1) * (3 - 0)` | 26 |
| &nbsp;&nbsp;&nbsp;&nbsp;**Push to stack** | | - Indices: `[3]` <br> - Elements: `[4]` |  |  | 26 |
| **Processing index 4** | nums[4] = 1 | - Indices: `[3]` <br> - Elements: `[4]` | Stack is non-empty? True and (top of stack: 4) <= (current element: 1)? False |  | 26 |
| &nbsp;&nbsp;&nbsp;&nbsp;**Push to stack** | | - Indices: `[3, 4]` <br> - Elements: `[4, 1]` |  |  | 26 |
| **Processing index 5** | end of array | - Indices: `[3, 4]` <br> - Elements: `[4, 1]` | Stack is non-empty? True and end of array? True |  | 26 |
| &nbsp;&nbsp;&nbsp;&nbsp;**While Loop** | Popping index 4, which corresponds to 1 | - Indices: `[3]` <br> - Elements: `[4]` |  | `output += 1 * (4 - 3) * (5 - 4)` | 27 |
| &nbsp;&nbsp;&nbsp;&nbsp;**While Loop** | Popping index 3, which corresponds to 4 | - Indices: `[]` <br> - Elements: `[]` |  | `output += 4 * (3 - -1) * (5 - 3)` | 59 |
| &nbsp;&nbsp;&nbsp;&nbsp;**Push to stack** | | - Indices: `[5]` <br> - Elements: `[NA]` (Dummy index 5) |  |  | 59 |

</center>

## Time Complexity

The time complexity of the minimum and maximum span calculations are both $O(n)$, where $n$ is the number of elements in the input array `nums`. Therefore, the overall time complexity of the algorithm is $O(n)$.

## Space Complexity

Two stacks are used to store the indices of the elements in the input array `nums`. If the input array is strictly increasing or decreasing, the space complexity of the stack is $O(n)$ in the worst case.

---

# Number of Valid Subarrays

Returns the number of non-empty subarrays where the leftmost element is not larger than any other elements in the subarray.

## Explanation

Given `nums = [1, 4, 2, 5, 3]`, the number of valid subarrays can be calculated as follows:

### Stack Processing

<center>

| Iteration           | Details                                            | Stack - Indices       | Stack - Elements     | Next Smaller Array          | Condition                                                                                   |
|---------------------|----------------------------------------------------|-----------------------|----------------------|-----------------------------|---------------------------------------------------------------------------------------------|
| **Initialization**  | Initialize stack and next_smaller array            | `[]`                  | `[]`                 | `[5, 5, 5, 5, 5]`            |                                                                                             |
| **Processing index 0** | nums[0] = 1                                       | `[]`                  | `[]`                 | `[5, 5, 5, 5, 5]`            | Stack is empty, so no popping. Push index 0 to the stack.                                   |
|                     | Push to stack                                      | `[0]`                 | `[1]`                | `[5, 5, 5, 5, 5]`            |                                                                                             |
| **Processing index 1** | nums[1] = 4                                       | `[0]`                 | `[1]`                | `[5, 5, 5, 5, 5]`            | Stack is non-empty and top of stack (1) is not greater than current element (4), so no pop. |
|                     | Push to stack                                      | `[0, 1]`              | `[1, 4]`             | `[5, 5, 5, 5, 5]`            |                                                                                             |
| **Processing index 2** | nums[2] = 2                                       | `[0, 1]`              | `[1, 4]`             | `[5, 5, 5, 5, 5]`            | Stack is non-empty and top of stack (4) is greater than current element (2), so pop index 1.|
|                     | Pop index 1, set next_smaller[1] = 2               | `[0]`                 | `[1]`                | `[5, 2, 5, 5, 5]`            | Update `next_smaller[1]` to 2 because 2 is the next smaller element after 4.                |
|                     | Push to stack                                      | `[0, 2]`              | `[1, 2]`             | `[5, 2, 5, 5, 5]`            |                                                                                             |
| **Processing index 3** | nums[3] = 5                                       | `[0, 2]`              | `[1, 2]`             | `[5, 2, 5, 5, 5]`            | Stack is non-empty and top of stack (2) is not greater than current element (5), so no pop. |
|                     | Push to stack                                      | `[0, 2, 3]`           | `[1, 2, 5]`          | `[5, 2, 5, 5, 5]`            |                                                                                             |
| **Processing index 4** | nums[4] = 3                                       | `[0, 2, 3]`           | `[1, 2, 5]`          | `[5, 2, 5, 5, 5]`            | Stack is non-empty and top of stack (5) is greater than current element (3), so pop index 3.|
|                     | Pop index 3, set next_smaller[3] = 4               | `[0, 2]`              | `[1, 2]`             | `[5, 2, 5, 4, 5]`            | Update `next_smaller[3]` to 4 because 3 is the next smaller element after 5.                |
|                     | Push to stack                                      | `[0, 2, 4]`           | `[1, 2, 3]`          | `[5, 2, 5, 4, 5]`            |                                                                                             |
| **End of array**    | Finished processing array                          | `[0, 2, 4]`           | `[1, 2, 3]`          | `[5, 2, 5, 4, 5]`            | No more elements to process, stack processing is complete.                                  |

</center>

### Counting Valid Subarrays

For each element `nums[i]` in the array, we determine how far to the right we can extend a subarray such that nums[i] remains the smallest element in that subarray. This is achieved by using the `next_smaller` array, which was previously populated during the stack processing.

* `next_smaller[i]`: This value tells us the index of the first element to the right of `nums[i]` that is smaller than `nums[i]`. If no such element exists, it is set to $n$ (the length of the array), indicating that `nums[i]` is the smallest element in all subarrays extending from $i$ to the end of the array.

* The difference `next_smaller[i] - i` gives us the number of elements in the subarray that starts at `nums[i]` and ends just before the element that is smaller than `nums[i]`. This distance directly translates into the number of valid subarrays where `nums[i]` is the smallest element.

<center>

| Iteration           | Index | Next Smaller Index | Calculation                 | Subarray Count | Cumulative Count |
|---------------------|-------|--------------------|-----------------------------|----------------|------------------|
| **Initialization**  |       |                    | Initialize count to 0        |                | 0                |
| **Subarrays from 0** | 0     | 5                  | `5 - 0 = 5`                  | 5              | 5                |
| **Subarrays from 1** | 1     | 2                  | `2 - 1 = 1`                  | 1              | 6                |
| **Subarrays from 2** | 2     | 5                  | `5 - 2 = 3`                  | 3              | 9                |
| **Subarrays from 3** | 3     | 4                  | `4 - 3 = 1`                  | 1              | 10               |
| **Subarrays from 4** | 4     | 5                  | `5 - 4 = 1`                  | 1              | 11               |

</center>

The total number of valid subarrays is `11`.

## Time Complexity

Let $n$ be the number of elements in the input array `nums`. In the worst case, i.e., the input array is strictly decreasing, every element except for the last element will be pushed and then popped from the stack. This leads to $O(n + (n - 1)) = O(2n - 1) = O(2n) = O(n)$ operations. 

The calculation of the number of valid subarrays also takes $O(n)$ time since we iterate over the `next_smaller` array, which has $n$ elements.

Therefore, the overall time complexity of the algorithm is $O(n)$.

## Space Complexity

Two data structures are used to store the indices of the elements:

* A monotonic increasing stack, which can be $O(n)$ in the worst case if the input array is strictly increasing (i.e., no elements are popped)

* An array to store the next smaller index for each element, which is always $o(n)$

Therefore, the overall space complexity of the algorithm is $O(n)$.
