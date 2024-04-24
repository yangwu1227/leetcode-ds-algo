// main.cpp
#include "find_numbers.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<int>> testNums = {{1, 5, 6, 7, 9, 10, 3, 12, 9}, 
                                               {2, 8, 13, 14, 15, 18, 20, 4, 7},
                                               {1, 2, 3, 4, 5, 6, 9, 27, 25, 32, 49, 14}};

    for (const auto &nums : testNums)
    {
        std::vector<int> result = findNumbers(nums);
        std::cout << "Given the input {";
        for (const auto &value : nums)
        {
            std::cout << value << (&value != &nums.back() ? ", " : "");
        }
        std::cout << "}, the result is {";
        for (const auto &value : result)
        {
            std::cout << value << (&value != &result.back() ? ", " : "");
        }
        std::cout << "}\n";
    }
    std::cout << std::endl;
    
    return 0;
}
