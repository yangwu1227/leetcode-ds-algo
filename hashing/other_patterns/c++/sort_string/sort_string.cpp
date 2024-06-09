// sort_string.cpp
#include "sort_string.hpp"
#include <string>
#include <unordered_map>

std::string sortString(const std::string &order, const std::string &s)
{
    std::unordered_map<char, int> sCharCounts;
    // O(n) where n is the number of characters in 's'
    for (const auto &sChar : s)
    {
        auto emplace_result = sCharCounts.try_emplace(sChar, 1);
        if (!emplace_result.second)
        {
            emplace_result.first->second++;
        }
    }

    // Reserve necessary capacity
    std::string permString;
    permString.reserve(s.size());

    // Let t = number of characters, including repeats that do appear in 'order', this costs O(t)
    for (const auto &orderChar : order)
    {
        auto iter = sCharCounts.find(orderChar);
        if (iter != sCharCounts.end())
        {
            // While the count is positive, keep adding the character to the output string
            while (iter->second > 0)
            {
                permString.push_back(orderChar);
                iter->second--;
            }
            // Remove the key
            sCharCounts.erase(orderChar);
        }
    }

    // Let k = number of characters that do no appear in 'order', this costs O(k)
    for (auto &[sChar, count] : sCharCounts)
    {
        while (count > 0)
        {
            permString.push_back(sChar);
            count--;
        }
    }

    return permString;
}