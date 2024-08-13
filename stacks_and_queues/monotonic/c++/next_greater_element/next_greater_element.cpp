// next_greater_element.cpp
#include "next_greater_element.hpp"
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>

std::vector<int> nextGreaterElement(const std::vector<int> &nums_1, const std::vector<int> &nums_2)
{
    std::unordered_map<int, int> nextGreaterMap;
    std::stack<int, std::vector<int>> monotonicIncreasing;
    for (auto &element : nums_2)
    {
        // As long as the stack is non-empty and the current element maintains the monotonic increasing property
        while (!monotonicIncreasing.empty() && monotonicIncreasing.top() < element)
        {
            // Hash the previous element and store the currrent element as its value, .e.g., previous element -> next greater element
            nextGreaterMap[monotonicIncreasing.top()] = element;
            monotonicIncreasing.pop();
        }
        monotonicIncreasing.push(element);
    }
    // Iterate over the first array and look up its next greater elements in the second array
    std::vector<int> output;
    output.reserve(nums_1.size());
    std::transform(
        nums_1.cbegin(), nums_1.cend(), std::back_inserter(output),
        [&nextGreaterMap](int element)
        {
            return nextGreaterMap.find(element) != nextGreaterMap.end() ? nextGreaterMap[element] : -1;
        });

    return output;
}
