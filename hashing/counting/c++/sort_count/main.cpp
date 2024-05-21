// main.cpp
#include "sort_count.hpp"
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> testStrings = {"tree", "Ilikepython3andc++20", "yangwuplayssoccerandpiano"};

    for (const auto &s : testStrings)
    {
        std::string sortedString = sortCount(s);
        std::cout << "Given the input string " << s << ", the sorted version of it is " << sortedString << '\n';
    }
    std::cout << std::endl;

    return 0;
}
