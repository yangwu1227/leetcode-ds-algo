// main.cpp
#include "intersection.hpp"
#include <vector>
#include <iostream>
#include <cassert>

int main()
{
    // Test cases
    std::vector<std::vector<std::vector<int>>> testNums = {
        {{7, 34, 45, 10, 12, 27, 13}, {27, 21, 45, 10, 12, 13}},
        {{1, 2, 3}, {4, 5, 6}},
        {{3, 1, 2, 4, 5}, {1, 2, 3, 4}, {3, 4, 5, 6}}};

    for (const auto &nums : testNums)
    {
        std::vector<int> ansLoop = Intersection::loop(nums);
        std::vector<int> ansSet = Intersection::set(nums);
        assert(ansSet == ansLoop);

        std::cout << "Given the input vector {";
        for (const auto &vector : nums)
        {
            std::cout << "{";
            for (const auto &value : vector)
            {
                std::cout << value << (&value != &vector.back() ? ", " : "");
            }
            std::cout << "}" << (&vector != &nums.back() ? ", " : "");
        }
        std::cout << "}, the intersection is {";
        for (const auto &value : ansSet)
        {
            std::cout << value << (&value != &ansSet.back() ? ", " : "");
        }
        std::cout << "}" << '\n';
    }
    std::cout << std::endl;

    return 0;
}
