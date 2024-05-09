// char_freq_equal.cpp
#include "char_freq_equal.hpp"
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

bool CharFrequency::setApproach(const std::string &s)
{
    std::unordered_map<char, int> counts;
    // O(n) to build the hash map
    for (const auto &character : s)
    {
        counts[character]++;
    }
    // O(n) to build the set
    std::unordered_set<int> result;
    for (const auto &[character, count] : counts)
    {
        result.insert(count);
    }

    return (result.size() == 1 ? true : false);
}

bool CharFrequency::lambdaApproach(const std::string &s)
{
    std::unordered_map<char, int> counts;
    // O(n) to build the hash map
    for (const auto &character : s)
    {
        counts[character]++;
    }
    // Iterator to the first (character, count)
    auto it = counts.begin();
    // Get the count of the first (character, count)
    int firstCount = it->second;

    // This takes std::all_of(first, last, p)
    // The p is a lambda function with capture clause [firstCount], taking in each (character, count) element as argument, and comparing each count with the first count
    // This costs 0(n)
    return std::all_of(it, counts.end(), [firstCount](const auto &characterCountPair)
                       { return firstCount == characterCountPair.second; });
}

bool CharFrequency::minMaxApproach(const std::string &s)
{
    std::unordered_map<char, int> counts;
    // O(n) to build the hash map
    for (const auto &character : s)
    {
        counts[character]++;
    }
    // This function std::minmax_element(first, last, cmp)
    // The cmp is a comparison function, returning true if the first argument is less than the second
    // At most O(3/2(n - 1), 0)
    std::pair pairMinMax = std::minmax_element(
        counts.begin(),
        counts.end(),
        [](const auto &currentCharacterCount, const auto &nextCharacterCount)
        { return currentCharacterCount.second > nextCharacterCount.second; });
    // If min and max counts are the same, then all characters have the same frequency
    return pairMinMax.first->second == pairMinMax.second->second;
}

bool CharFrequency::earlyReturnApproach(const std::string &s)
{
    std::unordered_map<char, int> counts;
    // O(n) to build the hash map
    for (const auto &character : s)
    {
        counts[character]++;
    }
    auto it = counts.begin();
    int firstCount = it->second;
    // If all counts are equal, this loop is O(n)
    for (const auto &characterCountPair : counts)
    {
        int currentCount = characterCountPair.second;
        // Return false as soon as we encounter a different count
        if (currentCount != firstCount)
        {
            return false;
        }
    }

    // If we get here, then all counts are the same
    return true;
}
