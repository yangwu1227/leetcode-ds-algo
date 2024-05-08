// intersection.hpp
#include "intersection.hpp"
#include <vector>
#include <unordered_map>
#include <set>

std::vector<int> Intersection::loop(const std::vector<std::vector<int>> &nums)
{
    if (nums.empty())
        return {};

    std::unordered_map<int, int> counts;
    // O(n * m) to build the hash map for n vectors each with m elements on average
    for (const auto &vector : nums)
    {
        for (const auto &value : vector)
        {
            counts[value]++;
        }
    }

    std::vector<int> ans;
    ans.reserve(counts.size());
    // O(n * m) operation
    for (const auto &[value, count] : counts)
    {
        if (count == nums.size())
        {
            ans.push_back(value);
        }
    }

    // O(m * log * m) sorting
    std::sort(ans.begin(), ans.end());

    return ans;
}

std::vector<int> Intersection::set(const std::vector<std::vector<int>> &nums)
{
    if (nums.empty())
        return {};

    // Initialize a set with the first vector's elements
    std::set<int> result(nums[0].begin(), nums[0].end());

    // Iterate over the remaining vectors starting from the second one
    for (size_t i = 1; i < nums.size(); ++i)
    {
        std::set<int> current(nums[i].begin(), nums[i].end());
        std::set<int> temp;

        // Use set_intersection to find common elements between result and current
        std::set_intersection(result.begin(), result.end(),
                              current.begin(), current.end(),
                              std::inserter(temp, temp.begin()));

        // Update the result with the intersection result O(1)
        result.swap(temp);
    }

    // Convert set back to vector O(m)
    return std::vector<int>(result.begin(), result.end());
}
