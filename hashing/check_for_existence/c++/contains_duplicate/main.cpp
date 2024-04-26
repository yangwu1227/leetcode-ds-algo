// main.cpp
#include "contains_duplicate.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<std::vector<int>> testNums = {{1, 2, 3, 1},
                                              {1, 2, 3, 4},
                                              {1, 1, 1, 3, 3, 4, 3, 2, 4, 2}};

    for (const auto &nums : testNums)
    {
        bool result = containsDuplicate(nums);
        std::cout << "The input {";
        for (const auto &value : nums)
        {
            std::cout << value << (&value != &nums.back() ? ", " : "");
        }
        std::cout << "} " << (result ? "contains" : "does not contain") << " duplicates" << '\n';
    }
    std::cout << std::endl;

    return 0;
}
