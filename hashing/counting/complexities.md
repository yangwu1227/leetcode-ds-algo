# Longest Substring with At Most K Distinct Characters

Given a string `s` and an integer `k`. Find the length of the longest substring that contains at most `k` distinct characters.

## Time Complexity

We use a dictionary to tracks the frequency of each character within the current sliding window. Operations such as insertion, deletion, and lookup have an average time complexity of $O(1)$.

We use a sliding window. The right pointer expands the window by including new characters, while the left pointer reduces the window when more than `k` distinct characters are present.

* As the right pointer advances, increment the count of the character in the dictionary, which is $O(1)$ on average.

* If there are more than `k` distinct characters `(len(counts) > k)`, move the left pointer rightward to reduce the window until the condition is met again. Remove characters from the dictionary when their count drops to zero. Decrementing a count is $O(1)$, and conditionally removing a character from the dictionary (if its count is zero) is also $O(1)$.

The right pointer moves across each character in the string once $O(n)$, and for each movement, the left pointer can move up only once per character ever included in the window. Hence, each character is involved in a constant number of operations (addition, potential decrement, and removal). Therefore, despite the nested loop appearance, the overall time complexity is $O(n)$.

## Space Complexity

The space used by the dictionary depends on the number of distinct characters in the string but is bounded by the size of the alphabet if `k` is not smaller than this size. In the worst case (with all unique characters and `k` equal to this number), the space complexity is $O(\min(k, |\sum|))$, where $|\sum|$ is the alphabet size (26 for lowercase English letters).

--

# Intersection of Multiple Arrays

Given a 2D array `nums` that contains `n` arrays of distinct integers, return a sorted array containing all the numbers that appear in all `n` arrays.

## Time Complexity

### Python3

#### Using `collections.defaultdict`

We use `np.concatenate(nums, axis=0)` to flatten the 2D array into a 1D array. The time complexity of this operation is $O(n \cdot m)$, where $n$ is the number of arrays and $m$ is the average length of each array. 

We use a `collections.defaultdict` to store the frequency of each number in the flattened array. The time complexity of building this dictionary is $O(n \cdot m)$.

We iterate over the dictionary to find the numbers that appear in all $n$ arrays. At most, if all elements are unique, the dictionary will contain $n \cdot m$ elements. The time complexity of this operation is $O(n \cdot m)$.

Finally, the intersection of $n$ arrays consists of the elements that are present in all the arrays. Therefore, the maximum number of elements in the intersection cannot exceed the number of elements in the smallest array, since an intersection cannot have more elements than the smallest contributing set. Assuming the average size of all $n$ set is $m$, the time complexity of sorting the intersection is $O(m \log m)$, where $m$ is the length of the average array.

The overall time complexity is:

$$
\begin{align*}
O(n \cdot m + n \cdot m + n \cdot m + m \log m) &= O(3n \cdot m + k \log k) \\
&= O(n \cdot m + m \log m)
\end{align*}
$$

#### Using `set.intersection_update`

We first build a set from the first array. The time complexity of this operation is $O(m)$, where `m` is the length of the average array.

We iterate over the remaining arrays and find the intersection of the current set with the next array. The time complexity of the intersection is $O(\text{min(len(set1), len(set2))})$ on average. Assuming that $m$ is the average length of each array, each intersection costs $O(m)$. Because we carry out this operation consecutively, the time complexity of finding the intersection of all `n` arrays is $O((n - 1) \cdot m)$.

Again, we can consider sorting as $O(m \log m)$, where `m` is the length of the average array.

The overall time complexity is:

$$
\begin{align*}
O(m + (n - 1) \cdot m + m \log m) &= O((n-1) \cdot m + m \log m) \\ 
&= O(n \cdot m + m \log m)
\end{align*}
$$

### C++

Constructing the initial set `result` from the first vector involves copying `m` elements, where `m` is the length of the average array. The time complexity is $O(m \log m)$ since each insertion into a set is $O(\log m)$. Note: a `std::set` is sorted compared to `std::unordered_set`, and so insertion may not be $O(1)$ average.

For each of the remaining `n-1` vectors, where `n` is the total number of vectors:

  - A new set `current` is created for each vector, which has a time complexity of $O(m \log m)$ for each vector
  - The `std::set_intersection` operation then finds the intersection of `result` and `current`. Assuming `N1 = m` represents the size of `result` and `N2 = m` (the size of each subsequent vector's set), the complexity of `std::set_intersection` is:
    $$
    \begin{align*}
    O(2 * (N1 + N2) - 1) &= O(2 * (m + m) - 1) \\
    &= O(2 * 2m - 1) \\
    &= O(4m - 1) \\
    &= O(m)
    \end{align*}
    $$
  - Updating the result using `std::set::swap` is `O(1)`.

The total complexity for the intersections is effectively $O((n-1) \cdot (m))$. A more practical upper bound might consider the input size of each set, leading to $O(n \cdot m)$.

Converting the output set back to a vector involves copying `m` elements, where `m` is the number of elements in the final intersection set. Again, this is due to the fact that the output cannot have more elements than the smallest contributing set, assumed to be `m`. The time complexity is $O(m \log m)$.

The major components of the complexity include the initialization and the intersections:

$$
O(m \log m + n \cdot m)
$$

## Space Complexity

If every element is unique, the space complexity of the dictionary is $O(n \cdot m)$, where `n` is the number of arrays and `m` is the average length of each array.
