// main.cpp
#include "isomorphic_strings.hpp"
#include <string>
#include <unordered_map>
#include <iostream>

int main()
{
    std::unordered_map<std::string, std::string> testCases = {
        {"egg", "add"},
        {"paper", "title"},
        {"foo", "bar"},
        {"bbbaaaba", "aaabbbba"}};

    for (const auto &[s, t] : testCases)
    {
        bool iso = isomorphic(s, t);
        std::cout << "Given s = '" << s << "' and t = '" << t << "', they are" << (iso ? " " : " not ") << "isomorphic to each other\n";
    }
    std::cout << std::endl;

    return 0;
}