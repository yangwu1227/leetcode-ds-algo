// group_anagrams.cpp
#include "group_anagrams.hpp"
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm> // For std::sort

std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string> &strs)
{
    if (strs.size() == 1)
    {
        return {strs};
    }

    std::unordered_map<std::string, std::vector<std::string>> results;
    for (const auto &str : strs)
    {
        // Copy before sorting inplace
        std::string strCopy = str;
        // O(c log c) where c is the length of each string
        std::sort(strCopy.begin(), strCopy.end());
        // O(1) push back amortized
        results[strCopy].push_back(str);
    }

    // Copy values into a vector
    std::vector<std::vector<std::string>> outputs;
    std::transform(
        results.begin(), results.end(),
        // An `std::insert_iterator` for inserting the anagram vectors (at the end of the out)
        std::inserter(outputs, outputs.end()),
        // A Lambda function to extract the value from each (std::string, std::vector<std::string>) pair
        [](const auto &pair)
        { return pair.second; });

    return outputs;
}
