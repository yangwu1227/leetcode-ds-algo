// main.cpp
#include "longest_substring_repeated.hpp"
#include <string>
#include <iostream>
#include <cassert>
#include <vector>

int main()
{
    std::vector<std::string> testStrings = {"abcabcbb", "bbbbb", "pwwkew", "Aa !@@!abdsc"};
    for (const auto &s : testStrings)
    {
        int lengthHashMap = LongestSubstringRepeated::hashMap(s);
        int lengthSlidingWindow = LongestSubstringRepeated::slidingWindowOptimized(s);
        assert(lengthSlidingWindow == lengthHashMap);
        std::cout << "Given the string '" << s << "', the longest substring with no repeats has " << lengthHashMap << " characters\n";
    }
    std::cout << std::endl;
    return 0;
}