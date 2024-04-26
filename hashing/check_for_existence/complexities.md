# Hash Map Interface

## C++

```c++
#include <unordered_map>
#include <iostream>

unordered_map<int, int> hashMap;

// Initialize it with some key value pairs
unordered_map<int, int> hashMap = {{1, 2}, {5, 3}, {7, 2}};

// Checking if a key exists: use the following syntax
hashMap.find(1) != hashMap.end(); // true
hashMap.find(9) != hashMap.end(); // false
// New addition from C++ 20
hashMap.contains(1); // true
hashMap.contains(9); // false

// Accessing a value given a key
hashMap[5]; // 3

// Access a key that does not exist creates the key with a default value of 0
hashMap[342]; // 0

// Adding or updating a key
// If the key already exists, the value will be updated
hashMap[5] = 6;

// If the key doesn't exist yet, the key value pair will be inserted
hashMap[9] = 15;

// Deleting a key: use the .erase() method
hashMap.erase(9);

// Get size
hashMap.size(); // 3

// Iterate over the key value pairs: .first gets the key and .second gets the value
for (auto const& pair: hashMap) {
    std::cout << pair.first << " " << pair.second << std::endl;
}
```

## Python

```python
hash_map = {}

# Initialize it with some key value pairs
hash_map = {1: 2, 5: 3, 7: 2}

# Checking if a key exists
1 in hash_map # True
9 in hash_map # False

# Accessing a value given a key
hash_map[5] # 3

# Access a key that does not exist raises a KeyError
hash_map[342] # KeyError

# Adding or updating a key
# If the key already exists, the value will be updated
hash_map[5] = 6

# If the key doesn't exist yet, the key value pair will be inserted
hash_map[9] = 15

# Deleting a key
del hash_map[9]

# Get size
len(hash_map) # 3

# Iterate over the key value pairs
for key, value in hash_map.items():
    print(key, value)

# Just the keys
for key in hash_map:
    print(key)

# Comprehension to get just the values
{key: hash_map[key] for key in hash_map}
```

---

# Two Sum

Given an array of integers `nums` and an integer `target`, return indices of two numbers such that they add up to `target`. We cannot use  the same index twice.

We may assume that each input would have exactly one solution.

## Time Complexity

There are two ways to implement this problem:

### One pass hash table

In one pass hash table, we iterate through the array and check if the complement of the current element exists in the hash table, i.e. `target - nums[i]`. If it does, we return the indices of the current element and the complement. If it doesn't, we add the current element to the hash table.

We iterate through the array once and each insertion and look up in the hash table costs $O(1)$ average. Therefore, the overall time complexity is $O(2n) = O(n)$.

### Two pass hash table

In two-pass hash table, we iterate through the array and build a hash table that maps the elements to their indices. Because insertion have have a time complexity of $O(1)$, the time complexity of building the hash table is $O(n)$.

We then iterate through the array and check if the complement of the current element exists in the hash table, i.e. `target - nums[i]`. If it does, we return the indices of the current element and the complement. This has a time complexity of $O(n)$ since each look up in the hash table costs $O(1)$ average.

The overall time complexity is $O(n + n) = O(2n) = O(n)$.

## Space Complexity

The space complexity of both approaches is $O(n)$ since we store the elements of the array in the hash table.

---

# First Letter to Appear Twice

Given a string `s`, return the first letter that appears twice in the string. We can assume that each input would have exactly one solution.

## Time Complexity

The time complexity of this approach is $O(n)$ where $n$ is the length of the string. We iterate through the string once and check if the current character has already appeared in the hash table. 

Regardless of whether we use a set or a hash map, the time complexity of insertion and look up is $O(1)$ average. Therefore, the overall time complexity is $O(n)$.

## Space Complexity

The space complexity of this approach is $O(m)$, where $m$ is the number of allowed characters in the string. In this case, because we are dealing with letters, $m = 26$. We store the characters that have appeared in the hash table or set. This ultimately means that the space complexity is constant and $O(1)$.

---

# Find Unique Values

Given an integer array `nums`, find all the unique numbers `x` in nums that satisfy the following: `x + 1` is not in `nums`, and `x - 1 `is not in `nums`.

## Time Complexity

In both Python and C++, we iterate through the array once to build the set of unique numbers. Then, we iterate through the array again to check if `x + 1` and `x - 1` are in the set. At most, the second iteration will have a time complexity of $O(n)$.

The total time complexity is $O(n + n) = O(2n) = O(n)$.

## Space Complexity

The space complexity of this approach is $O(n)$ since we store the elements of the array in the set.

---

# Check if the Sentence is Pangram

A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string `sentence` containing only lowercase English letters, return `true` if sentence is a pangram, or `false` otherwise.

## Time Complexity

We build a set from the input string, which has a time complexity of $O(n)$. This is because we iterate through the string once and add each character to the set. Insertion in a set (hash map) has a time complexity of $O(1)$ average in both Python and C++. We then get the length of the set, checking if it is equal to 26. The overall time complexity is $O(n)$.

## Space Complexity

The space complexity of this approach is $O(m)$, where $m$ is the number of allowed characters in the string. In this case, because we are dealing with letters, $m = 26$. We store the characters that have appeared in the set, which can be at most 26 characters. We can therefore think of the space complexity as constant and $O(1)$.

---

# Missing Number

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array.

## Examples

```
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
```

```
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
```

```
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
```

## Time Complexity

### Set Approach

For the hash map approach, we first build the set from the input array, which has a time complexity of $O(n)$. This is because we iterate through the array once and add each element to the set. Insertion in a set (hash map) has a time complexity of $O(1)$ average in both Python and C++.

We then iterate through the range `[0, n]` and check if each number is in the set. At worst, this loop will have $n+1$ iterations, so the time complexity of this step is $O(n)$.

The overall time complexity is $O(n + n) = O(2n) = O(n)$.

### Summation Approach

The summation approach uses the formula for the sum of the first `n` natural numbers, which is $\frac{n(n+1)}{2}$. We calculate the sum of the first `n` natural numbers and subtract the sum of the input array. 

The sum operations costs $O(n + 1) = O(n)$ for the first `n` natural numbers and $O(n)$ for the sum of the input array. The overall time complexity is $O(n + n) = O(2n) = O(n)$.

### XOR Approach

The XOR operation can be used to detect the missing number in a unique and efficient manner because of how it treats duplicate and zero values. 

#### Properties of XOR:

1. Identity: $a \oplus 0=a$
2. Inverse: $a \oplus a=0$
3. Commutative: $a \oplus b=b \oplus a$
4. Associative: $(a \oplus b) \oplus c=a \oplus(b \oplus c)$

#### Strategy:

- **Complete Range**: Create a sequence that includes every number from 0 to n, where n is the length of the original list `nums`. This means there is exactly one of each number from `0` to `n`.
- **Combine and XOR**: Append this sequence (0 to n) to the original list `nums`. This new combined list will contain two of each number from `0` to `n` except for one number that is missing from `nums`.
- **Apply XOR**: By XOR-ing all elements of this combined list:
  - Each number in the range `0` to `n` that appears twice will result in `0` when XOR-ed with itself (due to the **Inverse property**).
  - The missing number which appears only once will remain, as all other numbers cancel themselves out (due to the **Commutative and Associative properties**).

#### Example

Suppose `nums = [0, 1, 3]` and the length of `nums` (`n`) is 3. Thus, the range 0 to n is `[0, 1, 2, 3]`.

- The combined list would be: `[0, 1, 3, 0, 1, 2, 3]`
- XOR-ing all elements: `0 ⊕ 1 ⊕ 3 ⊕ 0 ⊕ 1 ⊕ 2 ⊕ 3`
  - All numbers except `2` appear twice and thus XOR to `0`.
  - The number `2` remains because it appears only once in the sequence (**Identity property**).

Thus, the missing number `2` is what remains after the XOR operation, and `reduce` applies this operation across the list, accumulating the result into a single value.

This method is efficient ($O(n)$ time complexity) and uses minimal additional space.

## Space Complexity

### Set Approach

The space complexity of this approach is $O(n)$ since we store the elements of the array in the set.

### Summation Approach

The space complexity of this approach is $O(1)$ since we only use a few extra variables to store the sum of the first `n` natural numbers and the sum of the input array. The space does not grow with the input size.

### XOR Approach

In Python, we allocate $O(n + 1)$ to store the full range, i.e., the sequence from `0` to `n`. In Python, we combine this range with the input list `nums` to create a new list. The combined list has a length of $2n + 1$, costing $O(2n + 1)$. We can consider all of this as $O(n)$, ignoring the constant and lower-order terms.

In C++, we also allocate $O(n + 1)$ space for the full range vector, but we do not create a new combined list. So the overall space complexity is $O(n + 1)$, which can be considered as $O(n)$.
