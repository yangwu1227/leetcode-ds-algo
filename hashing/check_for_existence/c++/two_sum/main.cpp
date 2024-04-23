// main.cpp
#include "two_sum.hpp"
#include <vector>
#include <map>
#include <iostream>
#include <cassert>

int main()
{
    std::map<std::vector<int>, int> testCases = {{{2, 7, 11, 15}, 9},
                                                 {{3, 2, 4}, 6},
                                                 {{5, 2, 7, 10, 3, 9}, 8},
                                                 {{3, 3}, 6}};
    for (const auto &[nums, target] : testCases)
    {
        std::vector<int> result1 = Solution::onePassTwoSum(nums, target);
        std::vector<int> result2 = Solution::twoPassesTwoSum(nums, target);
        assert(result1 == result2 && result1.size() == 2);

        std::cout << "Given the input {";
        for (const auto &value : nums)
        {
            std::cout << value << (&value != &nums.back() ? ", " : "");
        }
        std::cout << "} and target = " << target << ", the indices of the two numbers are {";
        std::cout << result1[0] << ", " << result2[1] << "}\n";
    }
    std::cout << std::endl;

    return 0;
}
