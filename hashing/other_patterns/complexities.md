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

### Bounds

Since both $m$ and $n$ are bounded by the size of the English alphabet, which is a constant $26$, the overall time complexity is $O(26 \times 3)=O(78)$ for the two hash maps approach and $O(26 \times 2)=O(52)$ for the one hash map approach.

Both of these can be considered as $O(1)$ time complexity.

## Space Complexity

For the one hash map approach, the space complexity is $O(m)$ since we store the counts of the characters in `magazine`.

For the two hash map approach, the space complexity is $O(m + n)$ for storing the counts of the characters in both `magazine` and `ransom_note`.

Similar to time complexity, because $m$ and $n$ are bounded by the size of the English alphabet, we can considered both approaches have constant space comlexity. Not matter how many characters are in the strings, the hash maps can have at most $26$ keys.

---

# Jewels and Stones

Given two strings `jewewls` and `stones`, return the number of `stones` that are considered `jewels`.

* Each character in `jewels` is unique, representing a stone type that is considered a jewel

* Each character in `stones` represents a stone. Y

## Time Complexity

### Hash Map Approach

We iterate through `stones` to build a hash map of the stone counts in $O(n)$ time, where $n$ is the length of the `stones` string.

Next, we iterate through `jewels` to get the count of each jewel in the hash map in $O(m)$ time, where $m$ is the length of the `jewels` string.

The overall time complexity is $O(n + m)$.

### Set Approach

This is the opposite of the hash map approach. We iterate through `jewels` to build a set of the jewel characters in $O(m)$ time.

Next, we iterate through `stones` to check if each stone is in the set in $O(n)$ time, summing the `True` values.

The overall time complexity is $O(m + n)$.

### Bounds

Since `jewels` and `stones` contain lower or upper case English alphabet characters, $m$ and $n$ are bounded by $26 \times 2 = 52$. Therefore, the overall time complexity is $O(52 + 52) = O(104) = O(1)$ regardless of the actual lengths of the strings.

## Space Complexity

### Hash Map Approach

We store the counts of the stones in the hash map, which can have up to $n$ keys in the worst case (i.e. no two stones are the same). Therefore, the space complexity is $O(n)$.

### Set Approach

We store the jewel characters in the set, which can have up to $m$ keys in the worst case (i.e. no two jewels are the same). Therefore, the space complexity is $O(m)$.

### Bounds

Again, since $m$ and $n$ are bounded by $52$, the space complexity can be considered const, $O(52) = O(1)$.

--- 

# Longest Substring Without Repeating Characters

Given a string `s`, return the length of the longest substring without repeating characters.

## Explanation

### Hash Map Approach

The input string is `"abcabcbb"`:

<center>

| Character | Left Pointer | Right Pointer | Character Counts                  | Action                           | Window         | Resulting `window_len` |
|-----------|---------------|---------------|-----------------------------------|----------------------------------|----------------|------------------------|
| a         | 0             | 0             | {'a': 1}                          | Expand window, add 'a'           | a              | 1                      |
| b         | 0             | 1             | {'a': 1, 'b': 1}                  | Expand window, add 'b'           | ab             | 2                      |
| c         | 0             | 2             | {'a': 1, 'b': 1, 'c': 1}          | Expand window, add 'c'           | abc            | 3                      |
| a         | 1             | 3             | {'a': 1, 'b': 1, 'c': 1}          | Duplicate 'a', move left pointer | bca            | 3                      |
| b         | 2             | 4             | {'a': 1, 'b': 1, 'c': 1}          | Duplicate 'b', move left pointer | cab            | 3                      |
| c         | 3             | 5             | {'a': 1, 'b': 1, 'c': 1}          | Expand window, add 'c'           | abc            | 3                      |
| b         | 5             | 6             | {'a': 0, 'b': 1, 'c': 1}          | Duplicate 'b', move left pointer | cb             | 3                      |
| b         | 7             | 7             | {'a': 0, 'b': 1, 'c': 0}          | Duplicate 'b', move left pointer | b              | 3                      |

</center>


### Using Optimized Sliding Window Approach

<center>

| Character | Left Pointer | Right Pointer | Character Indices                  | Window         | Resulting `window_len` |
|-----------|---------------|---------------|-----------------------------------|----------------|------------------------|
| a         | 0             | 0             | {'a': 1}                          | a              | 1                      |
| b         | 0             | 1             | {'a': 1, 'b': 2}                  | ab             | 2                      |
| c         | 0             | 2             | {'a': 1, 'b': 2, 'c': 3}          | abc            | 3                      |
| a         | 1             | 3             | {'a': 4, 'b': 2, 'c': 3}          | bca            | 3                      |
| b         | 2             | 4             | {'a': 4, 'b': 5, 'c': 3}          | cab            | 3                      |
| c         | 3             | 5             | {'a': 4, 'b': 5, 'c': 6}          | abc            | 3                      |
| b         | 5             | 6             | {'a': 4, 'b': 7, 'c': 6}          | cb             | 3                      |
| b         | 7             | 7             | {'a': 4, 'b': 8, 'c': 6}          | b              | 3                      |

</center>

## Time Complexity

### Hash Map Approach

We iterate through the input string containing $n$ characters:

  - Add or increment the count of `s[right]` in the hash map in $O(1)$ time.

  - While the count of `s[right]` is greater than $1$, we shrink the window by decrementing the count of `s[left]` in the hash map and incrementing the left pointer in $O(1)$ time.

  - Update the maximum window length in $O(1)$ time.

Each character is visited at most twice by the two pointers:

1. Once by the right pointer, which iterates through the string
2. Once by the left pointer, which shrinks the window

The overall time complexity is proportional to $O(2n)=O(n)$.

### Optimized Sliding Window Approach

The idea here is that if `s[right]` has a duplicates in the window `[left, right)` with the index `right`, we can skip all the elements in the range `[left, right]` by moveing the left pointer directly to `right + 1`. 

This resets the window to a new starting point without any duplicates. Therefore, there is no need to increment the left pointer one by one and may result in fewer visits to each character.

Again, we iterate through the input string containing $n$ characters:

  - Check if the character at `right` is in the hash map in $O(1)$ time.

  - If the character is in the hash map, we update the left pointer to either 

    - the current left pointer or 
    - one after the last occurrence of the character in the hash map
  
    This costs in $O(1)$ and ensures that the left pointer is skiped to the right of the last occurrence of a repeated character.

  - Update the maximum window length in $O(1)$ time.

  - Update the index of `s[right]` in the hash map to `right + 1` in $O(1)$ time, which ensures that if this character is encountered again, the left pointer can be moved directly to this index.

  Thus, the overall number of times each character is visited may be less than $2n$. Still, the time complexity is $O(n)$ amortized.


## Space Complexity

### Hash Map Approach

We store the counts of the characters in the hash map, which can have up to $n$ keys in the worst case (i.e. no two characters are the same). Therefore, the space complexity is $O(n)$.

### Optimized Sliding Window Approach

This approach uses a hash map to store the indices of the characters; similar to the hash map approach, in the worst case, the hash map can have up to $n$ keys. Therefore, the space complexity is $O(n)$.

### Bounds

As of the time of writing, the extended ASCII character set has $256$ characters, including upper and lower case English alphabets, digits, and symbols.

In the worst case, the input string `s` have all the characters in the extended ASCII set. Therefore, the maximum number of keys in the hash map is $256$, which can be considered a constant.

---

# Isomorphic Strings

Given two strings `s` and `t`, determine if they are isomorphic. Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced to get `t`.

Note: All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same 
character, but a character may map to itself.

## Explanation

Let `s = "paper"` and `t = "title"`:

<center>

| Iteration | s_char | t_char | Action                          | s_to_t                                 | t_to_s                                 |
|-----------|--------|--------|---------------------------------|----------------------------------------|----------------------------------------|
| 0         | p      | t      | Mapping p to t and t to p       | {'p': 't'}                             | {'t': 'p'}                             |
| 1         | a      | i      | Mapping a to i and i to a       | {'p': 't', 'a': 'i'}                   | {'t': 'p', 'i': 'a'}                   |
| 2         | p      | t      | p is already mapped to t        | {'p': 't', 'a': 'i'}                   | {'t': 'p', 'i': 'a'}                   |
| 3         | e      | l      | Mapping e to l and l to e       | {'p': 't', 'a': 'i', 'e': 'l'}         | {'t': 'p', 'i': 'a', 'l': 'e'}         |
| 4         | r      | e      | Mapping r to e and e to r       | {'p': 't', 'a': 'i', 'e': 'l', 'r': 'e'} | {'t': 'p', 'i': 'a', 'l': 'e', 'e': 'r'} |

</center>

Let `s = "bbbaaaba"` and `t = "aaabbbba"`:

<center>

| Iteration | s_char | t_char | Action                                                                  | s_to_t                | t_to_s                |
|-----------|--------|--------|-------------------------------------------------------------------------|-----------------------|-----------------------|
| 0         | b      | a      | Mapping b to a and a to b                                               | {'b': 'a'}            | {'a': 'b'}            |
| 1         | b      | a      | b is already mapped to a                                                | {'b': 'a'}            | {'a': 'b'}            |
| 2         | b      | a      | b is already mapped to a                                                | {'b': 'a'}            | {'a': 'b'}            |
| 3         | a      | b      | Mapping a to b and b to a                                               | {'b': 'a', 'a': 'b'}  | {'a': 'b', 'b': 'a'}  |
| 4         | a      | b      | a is already mapped to b                                                | {'b': 'a', 'a': 'b'}  | {'a': 'b', 'b': 'a'}  |
| 5         | a      | b      | a is already mapped to b                                                | {'b': 'a', 'a': 'b'}  | {'a': 'b', 'b': 'a'}  |
| 6         | b      | b      | b is already mapped to a \| Conflict detected: b cannot map to b        | {}                    | {}                    |

</center>

## Time Complexity

Create two hash maps, `s_to_t` and `t_to_s`, to store the mappings of characters from `s` to `t` and `t` to `s`, respectively.

We iterate through the input strings `s` and `t`, each containing $n$ characters:

  - **If**: we check if `s[i]` is already in `s_to_t`, which means that it has already been mapped to a character in `t`. 
    - If it is, we check if `s[i]` is mapped to a different character in `t` than `t[i]`. If it is, we return `False` since the same `s[i]` character cannot be mapped to two different characters in `t`.
    
    The above requires a look up in the hash map `s[i] in s_to_t` in $O(1)$ time and an equality check `s_to_t[s[i]] != t[i]`, which is also $O(1)$ time.
  
  - **Else If**: if `s[i]` is not already in `s_to_t`, we check if `t[i]` is already in `t_to_s`, which means that it has already been mapped to a character in `s`.
    - If it is, we check if `t[i]` is mapped to a different character in `s` than the current `s[i]`. If it is, we return `False` since the same `t[i]` character cannot be mapped to by two different characters in `s`.

    Again, look up `t[i] in t_to_s` and the equality check `t_to_s[t[i]] != s[i]` are both $O(1)$ operations.

  - **Else**: The first and second checks can both return `True`, but if neither of them does, we add the mappings `s[i]` to `t[i]` and `t[i]` to `s[i]` in $O(1)$ time.

We would only iterate through the entire input strings when there are no conflicts in the mappings. Therefore, the overall time complexity is $O(n)$.

## Space Complexity

We use two hash maps to trade off space for time. Without the second hash map that maps characters in `t` to characters in `s`, we would need to iterate through the values of `s_to_t` hash map to check if a character in `t` is already mapped to a character in `s` during each iteration through the input strings.

In the worst case, every character in `s` and `t` is unique, so both hash maps contain $n$ keys, leading to a space complexity of $O(n)$.