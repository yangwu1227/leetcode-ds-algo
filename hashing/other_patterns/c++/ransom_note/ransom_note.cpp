// ransom_note.cpp
#include "ransom_note.hpp"
#include <unordered_map>
#include <string>

bool RansomNote::oneHashMap(const std::string &ransomNote, const std::string &magazine)
{
    // O(n) where n is the length of 'magazine'
    std::unordered_map<char, int> magazineCounts;
    for (int i = 0; i < magazine.size(); i++)
    {
        auto emplace_result = magazineCounts.try_emplace(magazine[i], 1);
        if (!emplace_result.second)
        {
            emplace_result.first->second++;
        }
    }
    // O(m) where m is the length of 'ransomNote'
    for (int j = 0; j < ransomNote.size(); j++)
    {
        // Subtract from the count of each character from the hash map, if no such character exists, the [ operator convenient initializes the count to 0
        magazineCounts[ransomNote[j]]--;
        // If the count of any character reaches below zero, it either means that 1) there is not enough of that character or 2) no such character exist in 'magazine'
        if (magazineCounts[ransomNote[j]] < 0)
        {
            return false;
        }
    }
    return true;
}

bool RansomNote::twoHashMaps(const std::string &ransomNote, const std::string &magazine)
{
    // O(n) where n is the length of 'magazine'
    std::unordered_map<char, int> magazineCounts;
    for (int i = 0; i < magazine.size(); i++)
    {
        auto emplace_result = magazineCounts.try_emplace(magazine[i], 1);
        if (!emplace_result.second)
        {
            emplace_result.first->second++;
        }
    }
    // O(m) where m is the length of 'ransomNote'
    std::unordered_map<char, int> ransomNoteCounts;
    for (int i = 0; i < ransomNote.size(); i++)
    {
        auto emplace_result = ransomNoteCounts.try_emplace(ransomNote[i], 1);
        if (!emplace_result.second)
        {
            emplace_result.first->second++;
        }
    }
    // O(m) where m is the length of 'ransomNote'
    for (int j = 0; j < ransomNote.size(); j++)
    {
        // Check if the there are enough counts in 'magazine' to reproduce 'ransomNote'
        if (magazineCounts[ransomNote[j]] < ransomNoteCounts[ransomNote[j]])
        {
            return false;
        }
    }
    return true;
}