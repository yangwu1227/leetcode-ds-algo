// close_strings.cpp
#include "close_strings.hpp"
#include "sort_counts.hpp"
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <boost/range/combine.hpp> // For boost::combine and boost::tie
#include <algorithm>               // For std::sort

std::vector<int> sortCounts(const std::unordered_map<char, int> &countsMap)
{
    std::vector<int> outputVec;
    outputVec.reserve(countsMap.size());
    std::transform(
        countsMap.begin(), countsMap.end(),
        // An `std::insert_iterator` for inserting the anagram vectors (at the end of the out)
        std::inserter(outputVec, outputVec.end()),
        // A Lambda function to extract the value from each (std::string, std::vector<std::string>) pair
        [](const auto &pair)
        { return pair.second; });
    std::sort(outputVec.begin(), outputVec.end());
    return outputVec;
}

bool closeStrings(const std::string &first, const std::string &second)
{
    if (first.size() != second.size())
    {
        return false;
    }

    // Hash maps to store counts and sets to store keys
    std::unordered_map<char, int> firstCounts, secondCounts;
    std::unordered_set<char> firstChars, secondChars;
    for (const auto &tuple : boost::combine(first, second))
    {
        char firstChar, secondChar;
        boost::tie(firstChar, secondChar) = tuple;
        // Add the characters to the sets
        firstChars.emplace(firstChar), secondChars.emplace(secondChar);
        // Count
        auto emplaceResultFirst = firstCounts.try_emplace(firstChar, 1);
        auto emplaceResultSecond = secondCounts.try_emplace(secondChar, 1);
        if (!emplaceResultFirst.second)
        {
            emplaceResultFirst.first->second++;
        }
        if (!emplaceResultSecond.second)
        {
            emplaceResultSecond.first->second++;
        }
    }

    // Copy the counts to vectors
    std::vector<int> firstCountsVec = sortCounts(firstCounts);
    std::vector<int> secondCountsVec = sortCounts(secondCounts);

    // Check I: Both strings must contain the exact same unique characters, ensuring that characters can be swapped to match each other
    bool checkOne = (firstCountsVec == secondCountsVec);
    // Check II: Both strings must have the same count distribution of characters, ensuring that characters can be transformed into each other
    bool checkTwo = (firstChars == secondChars);

    return checkOne && checkTwo;
}