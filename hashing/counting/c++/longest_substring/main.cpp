// main.cpp
#include "longest_substring.hpp"
#include "custom_rsg.hpp"
#include <string>
#include <iostream>
#include <unordered_map>

int main()
{
    std::unordered_map<std::string, int> testCases = {{generateRandomString(10), 3}, {generateRandomString(15), 6}, {generateRandomString(7), 2}};
    for (const auto &[s, k] : testCases)
    {
        int ans = longestSubstring(s, k);
        std::cout << "Given the input string '";
        for (const auto &character : s)
        {
            std::cout << character;
        }
        std::cout << "' and k = " << k << ", the longest substring with at most " << k << " distinct character has length " << ans << '\n';
    }
    std::cout << std::endl;
    return 0;
}
