// main.cpp
#include "backspace_compare.hpp"
#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
    std::unordered_map<std::string, std::string> testCases = {
        {"y#fo##f", "y#f#o##f"},
        {"a#c", "b"},
        {"ab#c", "ad#c"}};
    for (const auto &[s, t] : testCases)
    {
        CompareStrings compStr = CompareStrings();
        bool same = compStr.compare(s, t);
        std::cout << "Given s = '" << s << "' and t = '" << t << "', the strings are " << (same ? "the" : "not the") << " same\n";
    }
    std::cout << std::endl;

    return 0;
}
