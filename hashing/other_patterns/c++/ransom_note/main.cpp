// main.cpp
#include "ransom_note.hpp"
#include <string>
#include <iostream>
#include <unordered_map>
#include <cassert>

int main()
{
    std::unordered_map<std::string, std::string> testCases = {
        {"a", "b"},
        {"aa", "ab"},
        {"aag", "gagaz"},
        {"fffbfg", "effjfggbffjdgbjjhhdegh"}};

    for (const auto &[ransomNote, magazine] : testCases)
    {
        bool oneHashMap = RansomNote::oneHashMap(ransomNote, magazine);
        bool twoHashMaps = RansomNote::twoHashMaps(ransomNote, magazine);
        assert(oneHashMap == twoHashMaps);
        std::cout << "Ransom note = '" << ransomNote << "' " << (oneHashMap ? "can" : "cannot") << " be constructed from letters in magazine = '" << magazine << "'\n";
    }
    std::cout << std::endl;

    return 0;
}