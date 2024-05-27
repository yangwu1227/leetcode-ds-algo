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

We iterate through the input array of strings of size $n$ once:

- Sorting each string takes $O(m + m \log m)$ time, where $m$ is the average length of a string.
  - In Python, `sorted` returns a list of characters, so we need to join them back to a string, which takes $O(m)$ time. 
  - In C++, `std::sort` sorts the string in-place, so we need to copy the string first, which again takes $O(m)$ time.
  
- We look up the sorted string in the hash map, which is $O(1)$ time. If the key does not exist, the value will be initialized with an empty list or vector. If the key exists, we append or push back the original string to the list or vector in $O(1)$ time amortized (since reallocation may occur).

- Finally, we convert the hash map values to a list of lists or vector of vectors. In the worst case, in which there are no matching anagrams, there will be $n$ groups, each containing one string. This takes $O(n)$ time.

Therefore, the overall time complexity, ignoring the lower order terms $m$ and $n$, is:

$$
\begin{align*}
O(n \cdot (m + m \log m) + n) = O(n \cdot m \log m)
\end{align*}
$$

## Space Complexity

### Keys

The space complexity is $O(n \cdot m)$, where $n$ is the number of strings and $m$ is the average length of a string. We store the sorted strings in the hash map, which can have up to $n$ keys in the worst case, each with a value of up to $m$ characters. 

### Values

The values are lists or vectors of strings. Each input string is stored in one of these lists or vectors. Therefore, the space complexity is still $O(n \cdot m)$ (i.e., the total number of characters among all strings).

Finally, the overall space complexity is then $O(2 n \cdot 2m) = O(n \cdot m)$.
