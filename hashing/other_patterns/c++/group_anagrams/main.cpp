// main.cpp
#include "group_anagrams.hpp"
#include <vector>
#include <string>
#include <iostream>

int main()
{
    std::vector<std::vector<std::string>> testStrings = {
        {"eat", "tea", "tan", "ate", "nat", "bat"},
        {""},
        {"a"},
        {"zhf", "fhz", "cpp", "python", "pcp", "statistics", "math", "tmah"}};

    for (const auto &strs : testStrings)
    {
        std::vector<std::vector<std::string>> results = groupAnagrams(strs);
        std::cout << "Given the input {";
        for (const auto &str : strs)
        {
            std::cout << str << (&str != &strs.back() ? ", " : "");
        }
        std::cout << "}, the anagrams results are {";
        for (const auto &group : results)
        {
            std::cout << "{";
            for (const auto &str : group)
            {
                std::cout << str << (&str != &group.back() ? ", " : "");
            }
            std::cout << "}" << (&group != &results.back() ? ", " : "");
        }
        std::cout << "}" << '\n';
    }
    std::cout << std::endl;

    return 0;
}
