# Group Anagrams

Given an array of strings `strs`, group the anagrams together.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

## Example

```
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

## Explanation

Given the input: `("zhf", "fhz", "cpp", "python", "pcp", "statistics", "math", "tmah")`:

<center>

| Iteration | Action                                      | Result                                                        |
|-----------|---------------------------------------------|---------------------------------------------------------------|
| 1         | Process `"zhf"`: Sort and append to key     | `results = {'fhz': ['zhf']}`                                   |
| 2         | Process `"fhz"`: Sort and append to key     | `results = {'fhz': ['zhf', 'fhz']}`                            |
| 3         | Process `"cpp"`: Sort and append to key     | `results = {'fhz': ['zhf', 'fhz'], 'cpp': ['cpp']}`            |
| 4         | Process `"python"`: Sort and append to key  | `results = {'fhz': ['zhf', 'fhz'], 'cpp': ['cpp'], 'hnopty': ['python']}` |
| 5         | Process `"pcp"`: Sort and append to key     | `results = {'fhz': ['zhf', 'fhz'], 'cpp': ['cpp', 'pcp'], 'hnopty': ['python']}` |
| 6         | Process `"statistics"`: Sort and append to key | `results = {'fhz': ['zhf', 'fhz'], 'cpp': ['cpp', 'pcp'], 'hnopty': ['python'], 'aiicssttt': ['statistics']}` |
| 7         | Process `"math"`: Sort and append to key    | `results = {'fhz': ['zhf', 'fhz'], 'cpp': ['cpp', 'pcp'], 'hnopty': ['python'], 'aiicssttt': ['statistics'], 'ahmt': ['math']}` |
| 8         | Process `"tmah"`: Sort and append to key    | `results = {'fhz': ['zhf', 'fhz'], 'cpp': ['cpp', 'pcp'], 'hnopty': ['python'], 'aiicssttt': ['statistics'], 'ahmt': ['math', 'tmah']}` |
| 9         | Convert `results` values to a list and return | `[['zhf', 'fhz'], ['cpp', 'pcp'], ['python'], ['statistics'], ['math', 'tmah']]` |

</center>

## Time Complexity

We iterate through the input array containing $n$ strings each with an average length of $m$:

- Sorting each string takes $O(m + m \log m)$ time, where $m$ is the average length of a string. The additional $m$ lower order term is due to the fact that:
  - In Python, `sorted` returns a list of characters, so we need to join them back to a string via `''.join(sorted_list_of_characters)`, which takes $O(m)$ time.
  - In C++, `std::sort` sorts the string in-place, so we need to copy the original string first, which again takes $O(m)$ time.
  
- We look up the sorted string in the hash map in $O(1)$ time. If the key does not exist, the value associated with that key will be initialized with an empty list or vector. If the key exists, we append or push back the original string to the list or vector in $O(1)$ amortized time (since reallocation may occur).

- Finally, we convert the hash map values to a list of lists or vector of vectors. In the worst case, in which there are no matching anagrams, there will be $n$ anagram groups, each containing one single string. So this conversion takes $O(n)$ time.

The overall time complexity, ignoring the lower order terms $m$ and $n$, is:

$$
\begin{align*}
O(n \cdot (m + m \log m) + n) = O(n \cdot m \log m)
\end{align*}
$$

## Space Complexity

### Keys

We store the sorted strings in the hash map, which can have up to $n$ keys in the worst case (i.e. no two strings are anagrams of each other), each with on average $m$ characters. Therefore, the space complexity of the keys is $O(n \cdot m)$.

### Values

The values are lists or vectors of strings. The input strings may be unevenly distributed among the anagram groups, but each string will be stored in exactly one group. Therefore, the space complexity of the values is still $O(n \cdot m)$ (i.e., the total number of characters in the input strings).

So, the overall space complexity is $O(2 n \cdot 2m) = O(n \cdot m)$.

---

# Minimum Consecutive Cards to Pick Up

Given a deck of `cards`, where `cards[i]` represents the value of the `ith` card, a pair of cards are matching if the cards have the same values.

Return the minimum number of cards we must pick up to find a matching pair of cards.

## Example

```
Input: cards = [3, 4, 2, 3, 4, 7]
Output: 4
Reason: If we pick the first four cards, we will find a matching pair of 3s.
```

## Explanation

Given the input: `[3, 4, 2, 3, 4, 7]` and initializing `min_distance` to `sys.maxsize` or `std::numeric_limits<int>::max()`:

<center>

| Iteration | Card | Action                                             | Result                                      |
|-----------|------|----------------------------------------------------|---------------------------------------------|
| 1         | 3    | Record the index of 3                              | `card_indices = {3: 0}`                     |
| 2         | 4    | Record the index of 4                              | `card_indices = {3: 0, 4: 1}`               |
| 3         | 2    | Record the index of 2                              | `card_indices = {3: 0, 4: 1, 2: 2}`         |
| 4         | 3    | Calculate distance (3 - 0 + 1 = 4), update min_distance | `min_distance = 4`                          |
|           |      | Update the index of 3                              | `card_indices = {3: 3, 4: 1, 2: 2}`         |
| 5         | 4    | Calculate distance (4 - 1 + 1 = 4), min_distance remains the same | `min_distance = 4`                          |
|           |      | Update the index of 4                              | `card_indices = {3: 3, 4: 4, 2: 2}`         |
| 6         | 7    | Record the index of 7                              | `card_indices = {3: 3, 4: 4, 2: 2, 7: 5}`   |
| 7         | -    | Return the minimum distance or -1 if no match      | `return 4`                                  |

</center>

## Time Complexity

We iterate through the input array containing $n$ cards:

  - We look up the card value in the hash map in $O(1)$ time. If the key already exists, this means that we have found a matching pair of cards.
    - Compute the distance between the current index and the index of previous occurrence of the card in $O(1)$ time.
    - Update the minimum distance in $O(1)$ time.
  - If the key does not exist, we set the value of the key to the current index in $O(1)$ *amortized* time (although hash collisions should be rare for built-in integer type).

The overall time complexity is $O(n)$.

## Space Complexity

We store the indices of the cards in the hash map, which can have up to $n$ keys in the worst case (i.e. no two cards are matching). Therefore, the space complexity is $O(n)$.

# Max Sum of a Pair With Equal Sum of Digits

Given an array of integers `nums`, find the maximum value of `nums[i] + nums[j]`, where `nums[i]` and `nums[j]` have the same digit sum (the sum of their individual digits). 

## Example

```
Input: nums = [18, 43, 36, 13, 7]
Output: 54
```

The pairs (i, j) that satisfy the conditions are:

  - (0, 2), both numbers have a sum of digits equal to $9$, and their sum is $18 + 36 = 54$.
  - (1, 4), both numbers have a sum of digits equal to $7$, and their sum is $43 + 7 = 50$.

## Explanation

The input array is `[18, 43, 36, 13, 7]`:

<center>

| Iteration | Number | Digit Sum Calculation | Digit Sum | hashMap                  | Action                                           | Resulting `ans` |
|-----------|--------|-----------------------|-----------|--------------------------|--------------------------------------------------|-----------------|
| 1         | 18     | `1 + 8 = 9`           | 9         | `{9: 18}`                | Record 18 with digit sum 9                       | 0               |
| 2         | 43     | `4 + 3 = 7`           | 7         | `{9: 18, 7: 43}`         | Record 43 with digit sum 7                       | 0               |
| 3         | 36     | `3 + 6 = 9`           | 9         | `{9: 36, 7: 43}`         | 18 + 36 = 54, update hashMap with max(18, 36)    | 54              |
| 4         | 13     | `1 + 3 = 4`           | 4         | `{9: 36, 7: 43, 4: 13}`  | Record 13 with digit sum 4                       | 54              |
| 5         | 7      | `7`                   | 7         | `{9: 36, 7: 43, 4: 13}`  | 43 + 7 = 50, update hashMap with max(43, 7)      | 54              |

</center>

## Time Complexity

We iterate through the input array containing $n$ numbers:

  - Calculate the digit sum of each number in $O(k)$ time, where $k$ is the *average* number of digits in an integer element.
  - Look up the digit sum in the hash map in $O(1)$ time. If the key already exists, this means that we have found a pair of numbers with the same digit sum.
    - Compute the sum of the pair of numbers in $O(1)$ time.
    - Check if the answer needs to be updated using `max(ans, nums[i] + nums[j])`, an $O(1)$ operation.
  - Update the hash map with the maximum value of the number with the same digit sum `max(nums[i], nums[j])` in $O(1)$ time. This ensures that `nums[j]` is the largest previously seen number with the same digit sum as `nums[i]`.

Considering the most significant operation, which is the digit sum calculation, the overall time complexity is $O(n \cdot k)$.

## Space Complexity

We store the numbers in the hash map, which can have up to $n$ keys in the worst case (i.e. no two numbers have the same digit sum). Therefore, the space complexity is $O(n)$.

---

# Equal Row and Column Pairs

Given a `n x  n` matrix of positive integers, return the number of pairs `(r_i, c_i)` such that row `r_i` and column `c_i` are equal. A row and column pair are considered equal if they contian the same elements in the same order, i.e., they are equal arrays.

## Examples

<div style="text-align: center;">
    <img src="diagrams/row_column_pair_ex_1.png" width="150" height="150">
</div>

```
Input: gird = [[3, 2, 1],[1, 7, 6],[2, 7, 7]]
Output: 1
``` 

The equal pairs are:

- Row 3 and column 2: `[2, 7, 7]`

<div style="text-align: center;">
    <img src="diagrams/row_column_pair_ex_2.png" width="170" height="170">
</div>

```
Input: grid = [[3, 1, 2, 2],[1, 4, 4, 5],[2, 4, 2, 2],[2, 4, 2, 2]]
Output: 3
```

The equal pairs are:

- Row 1 and column 1: `[3, 1, 2, 2]`
- Row 3 and column 3: `[2, 4, 2, 2]`
- Row 4 and column 3: `[2, 4, 2, 2]`

## Time Complexity

### Python

#### Numpy Approach

1. The conversion of the list of lists to a numpy array mostly likely takes $O(n^2)$ time since there are $n^2$ numbers in the input data structure. This conversion can be avoided if the input is already a numpy array.

2. We iterate through the numpy array `grid`, containing $n$ rows:
    - Conver the row to a tuple in $O(n)$ time (i.e. $n$ is the number of columns)
    - Increment the count of the row tuple in the hash map in $O(1)$ time

3. To build the column hash map, we can use the transpose of the numpy array. Transposing an array takes $O(1)$ time, since it is simply a swap of the shape and strides of the array. We iterate through the transposed array, containing $n$ columns:
    - Convert the column to a tuple in $O(n)$ time (i.e. $n$ is the number of rows)
    - Increment the count of the column tuple in the hash map in $O(1)$ time

4. Finally, we iterate through the column (but row would work as well) hash map:
    - For each column key, we check if that column exists in the row hash map in $O(1)$ time
    - If the key exists, we increment the count of equal pairs by the product of the counts of the row and column tuples in $O(1)$ time; this is because for a given array that appears $n$ times in the row hash map and $m$ times in the column hash map, there are $n \times m$ possible equal pairs

With all the above considered, the overall time complexity is:

$$
\begin{align*}
O(n^2 + n^2 + n^2 + n) &= O(3n^2 + n) \\
&= O(n^2)
\end{align*}
$$

With large input sizes, the quadratic term will dominate the linear term.

#### Built-in `List` Approach

Without using `numpy`, step 3 above would be modified as follows:

3. We iterate through from 1 to $n$ (the number of columns):
    - Build each column tuple in $O(n)$ time:
      - `row[j] for row in grid` takes $O(n)$ time since there are $n$ rows and indexing a list takes $O(1)$ time
      - The generator expression is wrapped in `tuple(row[j] for row in grid)`, and so the cost of this takes $O(n)$ time
    - Increment the count of the column tuple in the hash map in $O(1)$ time

The complexity of this step is again $O(n \times 2n)=O(2n^2)=O(n^2)$; therefore, the overall complexity remains $O(n^2)$, similar to the `numpy` approach.

The code is more verbose than the `numpy` approach, so it is better to use numpy input data structures instead of lists of lists.

### C++

The C++ approach is similar to the Python approach. The only difference is that we convert each vector to a `std::string` representation to use as a key in the hash map.

The overall time complexity is $O(n^2)$.

## Space Complexity

We need to store the row and column counts in two separate hash maps. In the worst case, where every row and column is unique, the hash maps will contain $n$ keys each. 

In Python, each key is a tuple of $n$ integers, and so the space complexity is $O(n \times n) = O(n^2)$.

In C++, each key is a string representation of the row or column, which have $n$ characters. Therefore, the space complexity is again $O(n \times n) = O(n^2)$.

--- 

# Ransom Note

Given two strings `ransom_note` and `magazine`, return `True` if `ransom_note` can be constructed by using the letters from `magazine`.

Each letter in `magazine` can only be used once in `ransom_note`.

## Time Complexity

Let $n$ be the length of the `ransom_note` string and $m$ be the length of the `magazine` string.

### One Hash Map Approach

We iterate through the `magazine` string containing $m$ characters and build a hash map of the character counts in $O(m)$ time.

Next, we iterate through the `ransom_note` string containing $n$ characters and decrement the count of each character in the above hash map. If the count of any character becomes negative, we return `False` since:

1. Either that character does not exist in the `magazine` string, in which case the default count is zero and decrementing it will make it negative
2. Or there is not enough of that character in the `magazine` string to construct the `ransom_note` string

The overall time complexity is $O(m + n)$.

### Two Hash Map Approach

We build two hash maps, one for the `magazine` string and one for the `ransom_note` string, each containing $m$ and $n$ characters, respectively. The time complexity of building these hash maps is $O(m + n)$.

Then, during the iteration through the `ransom_note` string, we check if the count of each character in the `magazine` hash map is less than the count of that character in the `ransom_note` hash map. If it is, we return `False` since there are not enough characters in the `magazine` string to construct the `ransom_note` string.

The overall time complexity is $O(m + n + n) = O(m + 2n) = O(m + n)$.

### Bounded by English Alphabet

Since both $m$ and $n$ are bounded by the size of the English alphabet, which is a constant $26$, the overall time complexity is $O(26 \times 3)=O(78)$ for the two hash maps approach and $O(26 \times 2)=O(52)$ for the one hash map approach.

Both of these can be considered as $O(1)$ time complexity.

## Space Complexity

For the one hash map approach, the space complexity is $O(m)$ since we store the counts of the characters in `magazine`.

For the two hash map approach, the space complexity is $O(m + n)$ for storing the counts of the characters in both `magazine` and `ransom_note`.

Similar to time complexity, because $m$ and $n$ are bounded by the size of the English alphabet, we can considered both approaches have constant space comlexity. Not matter how many characters are in the strings, the hash maps can have at most $26$ keys.
