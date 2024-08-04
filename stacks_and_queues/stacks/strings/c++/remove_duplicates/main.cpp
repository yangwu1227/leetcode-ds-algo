// main.cpp
#include "remove_duplicates.hpp"
#include <vector>
#include <string>
#include <iostream>

int main()
{
    std::vector<std::string> testStrings = {"abbaca", "azxxzy", "tzzxlgqwwgyw", "gzzgtxwxxw"};
    for (const auto &s : testStrings)
    {
        std::string uniqueString = removeDuplicates(s);
        std::cout << "After removing adjacent duplicates, " << s << " becomes " << uniqueString << '\n';
    }
    std::cout << std::endl;
}
