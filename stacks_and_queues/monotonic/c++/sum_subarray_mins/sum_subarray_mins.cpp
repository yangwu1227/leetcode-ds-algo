// sum_subarray_mins.cpp
#include "sum_subarray_mins.hpp"
#include <vector>
#include <stack>

int sumSubarrayMins(const std::vector<int> &x)
{
    if (x.size() == 1)
    {
        return x[0];
    }

    const int mod = 1e9 + 7;
    int n = x.size();

    // Each left[i] stores the number of contiguous subarrays ending at x[i] where x[i] is the minimum element, and the count including x[i] itself
    std::vector<int> leftSpans(n, 0);
    // Each right[i] stores the number of contiguous subarrays starting at x[i] where x[i] is the minimum element, and the count including x[i] itself
    std::vector<int> rightSpans(n, 0);

    std::stack<int, std::vector<int>> monotonicIncreasingLeft;
    // For each x[i], find its minimum span to its left
    for (int i = 0; i < n; ++i)
    {
        // While the stack is non-empty and the top of the stack is >= the current element
        while (!monotonicIncreasingLeft.empty() && x[monotonicIncreasingLeft.top()] >= x[i])
        {
            // Pop to ensure that we maintain a stack of indices where the elements corresponding to those indices are strictly less than x[i] to its left
            monotonicIncreasingLeft.pop();
        }
        // If the stack is empty, then there is just 1 continuous subarray where x[i] is the minimum, which is x[i] itself, so 0 + 1
        // Otherwise, the minimum span is calculated as the distance between i and the index of the previous smaller element at the top of the stack
        leftSpans[i] = monotonicIncreasingLeft.empty() ? i + 1 : i - monotonicIncreasingLeft.top();
        monotonicIncreasingLeft.push(i);
    }

    // Clear the stack to reuse it for right span calculation
    std::stack<int, std::vector<int>> monotonicIncreasingRight;
    // For each x[i], find its minimum span to its right
    for (int i = n - 1; i >= 0; --i)
    {
        // While the stack is non-empty and the top of the stack is > the current element
        while (!monotonicIncreasingRight.empty() && x[monotonicIncreasingRight.top()] > x[i])
        {
            // Pop to ensure that we maintain a stack of indices where the elements corresponding to those indices are strictly less than x[i] to its right
            monotonicIncreasingRight.pop();
        }
        // If the stack is empty, there is no smaller element to the right of x[i]
        // Otherwise, the minimum span is calculated as the distance between the index of the next smaller element at the top of the stack and i
        rightSpans[i] = monotonicIncreasingRight.empty() ? n - i : monotonicIncreasingRight.top() - i;
        monotonicIncreasingRight.push(i);
    }

    int output = 0;
    for (int i = 0; i < n; ++i)
    {
        // The contribution of x[i] as the minimum in all continuous subarrays where it is the minimum
        output = (output + static_cast<long long>(x[i]) * leftSpans[i] * rightSpans[i]) % mod;
    }

    return output;
}
