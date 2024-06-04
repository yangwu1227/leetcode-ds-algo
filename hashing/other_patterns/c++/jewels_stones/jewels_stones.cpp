// jewels_stones.cpp
#include "jewels_stones.hpp"
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <numeric> // For accumulate

int JewelStones::hashmap(const std::string &jewels, const std::string &stones)
{
    // O(n) to build, where n is the number of stones
    std::unordered_map<char, int> stonesCounts;
    for (const auto &stone : stones)
    {
        auto emplace_result = stonesCounts.try_emplace(stone, 1);
        if (!emplace_result.second)
        {
            // If key already exists, increment the count
            emplace_result.first->second++;
        }
    }

    // O(m) where m is the number of unique stone types
    int numJewels = 0;
    for (const auto &jewel : jewels)
    {
        // Count is initialized to zero if jewel does not appear in the set of stones
        numJewels += stonesCounts[jewel];
    }

    return numJewels;
}

int JewelStones::set(const std::string &jewels, const std::string &stones)
{
    // O(m) where m is the number of unique stone types
    std::unordered_set<char> jewelSets(std::begin(jewels), std::end(jewels));
    return std::accumulate(
        stones.begin(), stones.end(), 0,
        [&jewelSets](int currentCumSum, const auto &stone)
        {
            // Add to current cumulative sum if stone is considered a jewel, if not, do not add
            return (jewelSets.find(stone) != jewelSets.end() ? currentCumSum + 1 : currentCumSum);
        });
}