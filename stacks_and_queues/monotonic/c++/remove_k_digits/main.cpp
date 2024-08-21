// main.cpp
#include "remove_k_digits.hpp"
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::tuple<std::string, int>> data = {
        {"100000", 1},
        {"964310", 5},
        {"13579", 4},
        {"1432219", 3},
        {"12", 2},
        {"14957283", 6}};

    for (const auto &[num, k] : data)
    {
        std::string originalNum = num;
        std::string smallestNum = removeKDigits(originalNum, k);
        std::cout << "Given num = " << originalNum << ", the smallest number after removing " << k << " digits is " << smallestNum << '\n';
    }
    std::cout << std::endl;
    return 0;
}
