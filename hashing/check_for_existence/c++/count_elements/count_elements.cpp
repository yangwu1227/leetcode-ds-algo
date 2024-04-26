// count_elements.cpp
#include "count_elements.hpp"
#include <vector>
#include <unordered_set>

int countElements(const std::vector<int> &array)
{
    // Cost O(n) to build
    std::unordered_set<int> elementSet(array.begin(), array.end());
    int totalCount = 0;
    // Also O(n)
    for (const auto &value : array)
    {
        // Can also use contains from C++ 20
        if (elementSet.find(value + 1) != elementSet.end())
        {
            totalCount++;
        }
    }
    return totalCount;
}
