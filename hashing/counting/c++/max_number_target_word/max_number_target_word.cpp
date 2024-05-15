// max_number_target_word.cpp
#include "max_number_target_word.hpp"
#include <string>
#include <unordered_map>
#include <limits.h>
#include <algorithm>

int MaxNumberTargetWord::loop(const std::string &text, const std::string &targetWord)
{
    std::unordered_map<char, int> textCounts;
    std::unordered_map<char, int> targetCounts;
    for (const auto &character : text)
    {
        auto result = textCounts.emplace(character, 1);
        // If key already exists, increment it
        if (!result.second)
        {
            // Access the second element of (character, count)
            result.first->second++;
        }
    }
    for (const auto &character : targetWord)
    {
        auto result = targetCounts.emplace(character, 1);
        // If key already exists, increment it
        if (!result.second)
        {
            // Access the second element of (character, count)
            result.first->second++;
        }
    }

    // If there are not enough unique characters, return 0
    if (textCounts.size() < targetCounts.size())
    {
        return 0;
    }

    // Iterate through each character in the target word, compute number of times we can satisfy the minimum number of each character needed to form the target word
    // E.g. target_counts = {'a': 2} (two letter 'a' required) and char_counts = {'a': 6}, then 6 // 2 = 3, then we can potentially form up to three instances of target word
    int maxNumberInstances = INT_MAX;
    for (const auto &character : targetWord)
    {
        // If not found in text, return 0 (we could also use unorderd_map::contains c++20)
        if (textCounts.find(character) == textCounts.end())
        {
            return 0;
        }
        int numTimeSatisfied = textCounts[character] / targetCounts[character];
        // Keep updating the minimum, i.e., we can't form more instances than any character's maximum potential allows
        maxNumberInstances = std::min(maxNumberInstances, numTimeSatisfied);
    }

    return maxNumberInstances;
}

int MaxNumberTargetWord::transformReduce(const std::string &text, const std::string &targetWord)
{
    std::unordered_map<char, int> textCounts;
    std::unordered_map<char, int> targetCounts;
    for (const auto &character : text)
    {
        auto result = textCounts.emplace(character, 1);
        // If key already exists, increment it
        if (!result.second)
        {
            // Access the second element of (character, count)
            result.first->second++;
        }
    }
    for (const auto &character : targetWord)
    {
        auto result = targetCounts.emplace(character, 1);
        // If key already exists, increment it
        if (!result.second)
        {
            // Access the second element of (character, count)
            result.first->second++;
        }
    }

    // If there are not enough unique characters, return 0
    if (textCounts.size() < targetCounts.size())
    {
        return 0;
    }

    // Iterate through each character in the target word, compute number of times we can satisfy the minimum number of each character needed to form the target word
    // E.g. target_counts = {'a': 2} (two letter 'a' required) and char_counts = {'a': 6}, then 6 // 2 = 3, then we can potentially form up to three instances of target word
    int maxNumberInstances = std::transform_reduce(
        targetCounts.begin(),
        targetCounts.end(),
        // Initial values is the maximum integer
        INT_MAX,
        // Reduce function applied to each consecutive output of the transform function below
        [](int currentMax, int nextMax)
        { return std::min(currentMax, nextMax); },
        // Transform function applied to each (character, counts)
        [&textCounts](const auto &targetCount)
        {
            const auto &[character, counts] = targetCount;
            // If not found, return 0
            if (textCounts.find(character) == textCounts.end())
            {
                return 0;
            }
            return textCounts[character] / counts;
        });

    return maxNumberInstances;
}
