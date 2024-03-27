// main.cpp
#include <iostream>
#include <vector>
#include "sorted_two_sum.h"
#include <boost/range/combine.hpp> // Requires brew install boost (default location '/usr/local/include' must be added to includePath)

int main()
{

    std::vector<int> nums1 = {1, 2, 4, 6, 8, 9, 14, 15};
    std::vector<int> nums2 = {2, 9, 23, 89};
    int target1 = 13;
    int target2 = 39;

    // A vector of vectors of ints for nums and a vector of ints for targets
    std::vector<std::vector<int>> testNums = {nums1, nums2};
    std::vector<int> targets = {target1, target2};

    // Use boost::combine for iterating over test_nums and targets simultaneously
    for (const auto &tuple : boost::combine(testNums, targets))
    {

        std::vector<int> nums;
        int target;
        // Unpack the tuple, which is a (vector, target) pair
        boost::tie(nums, target) = tuple;

        bool pairExists = checkForTarget(nums, target);

        std::cout << "The input {";
        for (size_t j = 0; j < nums.size(); j++)
        {
            std::cout << nums[j];
            if (j < nums.size() - 1)
                std::cout << ", ";
        }
        std::cout << "} sums to target " << target << ": " << (pairExists ? "true" : "false") << std::endl;
    }

    return 0;
}
