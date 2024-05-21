// sort_count.cpp
#include "sort_count.hpp"
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <utility>

std::string sortCount(const std::string &s)
{
    // O(n) to build
    std::unordered_map<char, int> charCounts;
    for (const auto &character : s)
    {
        auto result = charCounts.try_emplace(character, 1);
        // If the character already exists, increment the count
        if (!result.second)
        {
            result.first->second++;
        }
    }

    // For k unique characters, this costs O(k)
    std::vector<std::pair<char, int>> charCountsVector(charCounts.begin(), charCounts.end());

    // O(k log k) to sort based on counts
    std::sort(charCountsVector.begin(), charCountsVector.end(),
              [](const auto &currentPair, const auto &nextPair)
              {
                  // Descending order so use >
                  return currentPair.second > nextPair.second;
              });

    std::string sortedString = "";
    for (const auto &[character, count] : charCountsVector)
    {
        sortedString += std::string(count, character);
    }

    return sortedString;
}
