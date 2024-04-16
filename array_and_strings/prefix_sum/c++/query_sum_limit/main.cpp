// main.cpp
#include "query_sum_limit.hpp"
#include <vector>
#include <iostream>
#include <boost/range/combine.hpp>

int main()
{
    std::cout << "Select the method to use for processing queries:\n";
    std::cout << "1: Original Method\n";
    std::cout << "2: Optimized Method\n";
    std::cout << "Enter your choice (1 or 2): ";
    int choice;
    std::cin >> choice;

    // Validate input
    if (choice != 1 && choice != 2)
    {
        std::cerr << "Invalid choice! Exiting...\n";
        return 1; // Exit with error code
    }

    // Test cases
    std::vector<std::vector<int>> testNums = {{1, 2, 3, 4, 5}, {-3, -1, -2, -4, -5}, {5, -1, 3, -2, 2, -4}};
    std::vector<std::vector<std::vector<int>>> testQueries = {{{0, 2}, {1, 3}, {0, 4}}, {{0, 1}, {2, 4}, {0, 4}}, {{0, 2}, {1, 4}, {2, 5}}};
    std::vector<int> testLimits = {2, -2, 3};

    // Solution class
    QuerySumHandler querySumHandler;

    for (const auto &zipped : boost::combine(testNums, testQueries, testLimits))
    {
        std::vector<int> nums;
        std::vector<std::vector<int>> queries;
        int limit;
        boost::tie(nums, queries, limit) = zipped;

        std::vector<bool> ans;
        if (choice == 1)
        {
            ans = querySumHandler.querySumLimit(nums, queries, limit);
        }
        else
        {
            ans = querySumHandler.querySumLimitOptimized(nums, queries, limit);
        }

        std::cout << "Given nums = {";
        for (const auto &num : nums)
        {
            std::cout << num << (&num != &nums.back() ? ", " : "");
        }
        std::cout << "}, queries = {";
        for (const auto &query : queries)
        {
            std::cout << "{";
            for (const auto &value : query)
            {
                std::cout << value << (&value != &query.back() ? ", " : "");
            }
            std::cout << "}" << (&query != &queries.back() ? ", " : "");
        }
        std::cout << "}, and limit = " << limit << ", the answer is ";
        std::cout << "{";
        for (const auto &answer : ans)
        {
            std::cout << std::boolalpha << answer << (&answer != &ans.back() ? ", " : "");
        }
        std::cout << "}" << std::endl;
    }

    return 0;
}
