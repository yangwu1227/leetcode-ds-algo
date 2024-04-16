# Psuedocode For Prefix Sum

Prefix sum is a technique that can be used on arrays (of numbers). The idea is to create an array prefix where `prefix[i]` is the sum of all elements up to the index `i` (inclusive). 

```
prefix = [nums[0]]
for (int i = 1; i < nums.length; i++)
    prefix.append(nums[i] + prefix[prefix.length - 1])
```

## Complexity

Prefix sum costs $O(n)$ time and $O(n)$ space to create the prefix array. Once the prefix array is created, we can calculate the sum of any subarray in $O(1)$ time.

<div style="text-align: center;">
    <img src="diagrams/prefix_sum.png" width="425" height="270">
</div>

Given an array `nums`, to find the sum of the subarray from index `i` to `j`, we can use the formula:

```
prefix[j] - prefix[i] + nums[i]
```

* The `prefix[i - 1]` is the sum of  all elements before index `i`, and `nums[i]` is the element at index `i`

* The `prefix[j]` is the sum of all elements up to and including `j`, and `prefix[i]` is the sum of all elements up to and including `i`. So, `prefix[j] - prefix[i]` is the sum of all elements from index `i` and `j` (not including `nums[i]`).

* Finally, we add `nums[i]` to get the sum of all elements from index `i` and `j` (inclusive).

# Subarray Sum Less than Limit

Given an integer array `nums`, an array `queries` where `queries[i] = [x, y]` and an integer `limit`, return a boolean array that represents the answer to each query. Each query is of the form `queries[i] = [x, y]` where `0 <= x < y < len(nums)`.

## Example

```
Input: nums = [1, 2, 3, 4], queries = [[1, 2], [2, 3]], limit = 6
Output: [true, false]
Explanation: 
    For the first query, the sum of the subarray [2, 3] is 5, which is less than the limit.
    For the second query, the sum of the subarray [3, 4] is 7, which is greater than the limit.
```

## Time Complexity

Without the prefix sum, answer each query would cost $O(n)$ time. If we have `q` queries, the total time complexity would be $O(nq)$. However, with the prefix sum, which takes $O(n)$ to build, we can answer each query in $O(1)$ time. The total time complexity is $O(n + 1 \times q) = O(n + q)$.

## Space Complexity

The space complexity is $O(n)$ to store the prefix sum.  We also use $O(q)$ space to store the result of each query. The total space complexity is $O(n + q)$.
