// main.cpp
#include "permutation_string.hpp"
#include <string>
#include <iostream>
#include <unordered_map>

int main()
{
    std::unordered_map<std::string, std::string> testStrings = {{"ab", "eidbaooo"}, {"adc", "dcda"}, {"dinitrophenylhydrazine", "dimethylhydrazine"}, {"a", "ab"}};
    for (const auto &[s1, s2] : testStrings)
    {
        bool containsPerm = checkInclusion(s1, s2);
        std::cout << "The string '" << s2 << "' " << (containsPerm ? "contains" : "does not contain") << " a permutation of the string '" << s1 << "'" << '\n';
    }
    std::cout << std::endl;

    return 0;
}
