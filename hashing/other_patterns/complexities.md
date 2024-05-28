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
