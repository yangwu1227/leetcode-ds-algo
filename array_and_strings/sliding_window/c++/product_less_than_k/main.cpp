// main.cpp
#include "product_less_than_k.hpp"
#include <vector>
#include <iostream>
#include <boost/range/combine.hpp>

int main()
{
    // Test cases
    std::vector<std::vector<int>> testNums = {
        {10, 5, 2, 6},
        {1, 2, 3},
        {9, 6, 3, 10}};
    std::vector<int> testK = {100, 0, 25};

    for (const auto &tuple : boost::combine(testNums, testK))
    {
        std::vector<int> nums;
        int k;
        boost::tie(nums, k) = tuple;

        int numSubarrays = numSubarraysProductLessThanK(nums, k);

        std::cout << "The input {";
        for (const auto &value : nums)
        {
            std::cout << value << (&value != &nums.back() ? ", " : "");
        }
        std::cout << "} contains " << numSubarrays << " subarrays where the product of all its elements is strictly less than " << k << (&nums != &testNums.back() ? '\n' : ' ');
    }
    std::cout << std::endl;

    return 0;
}
