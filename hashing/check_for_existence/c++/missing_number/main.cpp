// main.cpp
#include "missing_number.hpp"
#include <vector>
#include <iostream>
#include <cassert>

int main()
{
    std::vector<std::vector<int>> testNums = {{3, 0, 1}, {0, 1}, {9, 6, 4, 2, 3, 5, 7, 0, 1}};
    for (const std::vector<int> &nums : testNums)
    {
        int missingNumberSet = MissingNumber::setApproach(nums);
        int missingNumberSummation = MissingNumber::summationApproach(nums);
        int missingNumberXorAccumulate = MissingNumber::xorAccumulateApproach(nums);
        assert(missingNumberSet == missingNumberSummation && missingNumberSet == missingNumberXorAccumulate);

        std::cout << "Given the input {";
        for (const auto &value : nums)
        {
            std::cout << value << (&value != &nums.back() ? ", " : "");
        }
        std::cout << "}, the missing number is " << missingNumberXorAccumulate << '\n';
    }
    std::cout << std::endl;

    return 0;
}
