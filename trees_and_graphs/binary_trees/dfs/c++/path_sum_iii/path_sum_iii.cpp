// path_sum_iii.cpp
#include "path_sum_iii.hpp"
#include "tree_node.hpp"
#include <unordered_map>
#include <functional>
#include <variant>
#include <stdexcept>
#include <limits>
#include <cstdint>

int pathSum(TreeNode::ptr &root, int target)
{
    // Total paths found
    int count = 0;
    // If the tree is empty, return 0 path found
    if (!root)
        return count;

    // Define Sum type that can be easily changed between int and int64_t
    using Sum = int;

    // Current sum and counts hash map
    std::unordered_map<Sum, int> currSumCounts;
    Sum currSum = 0;

    // Helper function to detect potential integer overflow
    auto wouldOverflow = [](Sum a, int b) -> bool
    {
        if (b > 0 && a > std::numeric_limits<Sum>::max() - b)
            return true;
        if (b < 0 && a < std::numeric_limits<Sum>::min() - b)
            return true;
        return false;
    };

    // Depth first search lambda function
    std::function<void(TreeNode::ptr &)> depthFirstSearch = [&](TreeNode::ptr &node)
    {
        // Empty node
        if (!node)
            return;

        // Ensure node data is an integer
        if (!std::holds_alternative<int>(node->data))
            throw std::runtime_error("Non-integer data encountered in TreeNode");

        // Extract integer value and check for potential overflow before adding
        int currData = std::get<int>(node->data);

        // Check if adding current value would cause overflow
        if (wouldOverflow(currSum, currData))
        {
            // Switch to large number handling path
            handleLargePath(static_cast<std::int64_t>(currSum), node, count, target);
            return;
        }

        // Add current value to sum (safe now that we've checked for overflow)
        currSum += currData;

        // Check if the current sum matches the target, if so, we've found a path
        if (currSum == target)
            count++;

        // Check if (current sum - target) is already in the hash map
        Sum diff = currSum - target;
        if (auto searchResults = currSumCounts.find(diff); searchResults != currSumCounts.end())
        {
            // The count represents the number of valid paths, add them to the total count
            count += searchResults->second;
        }

        // Increment the count of the current sum
        currSumCounts[currSum]++;

        depthFirstSearch(node->left);
        depthFirstSearch(node->right);

        // Backtrace by decrementing the count of the current sum
        currSumCounts[currSum]--;

        // If the count of the current sum has reached zero, remove it
        if (!currSumCounts[currSum])
            currSumCounts.erase(currSum);
        // Subtract the current node data from the sum
        currSum -= currData;

        return;
    };

    depthFirstSearch(root);

    return count;
}

void handleLargePath(std::int64_t initialSum, TreeNode::ptr &node, int &count, const int target)
{
    // Switch to 64-bit arithmetic for paths with large numbers
    using BigSum = std::int64_t;
    std::unordered_map<BigSum, int> largeSumCounts;
    BigSum currSum = initialSum;
    BigSum bigTarget = static_cast<BigSum>(target);

    // Helper function to detect 64-bit overflow
    auto wouldOverflow64 = [](BigSum a, int b) -> bool
    {
        if (b > 0 && a > std::numeric_limits<BigSum>::max() - b)
            return true;
        if (b < 0 && a < std::numeric_limits<BigSum>::min() - b)
            return true;
        return false;
    };

    std::function<void(TreeNode::ptr &)> largeDFS = [&](TreeNode::ptr &node)
    {
        if (!node)
            return;

        if (!std::holds_alternative<int>(node->data))
            throw std::runtime_error("Non-integer data encountered in TreeNode");

        int currData = std::get<int>(node->data);

        // Check for overflow even in 64-bit path
        if (wouldOverflow64(currSum, currData))
        {
            throw std::overflow_error("Path sum too large even for 64-bit arithmetic");
        }

        currSum += static_cast<BigSum>(currData);

        if (currSum == bigTarget)
            count++;

        BigSum diff = currSum - bigTarget;
        if (auto searchResults = largeSumCounts.find(diff); searchResults != largeSumCounts.end())
        {
            count += searchResults->second;
        }

        largeSumCounts[currSum]++;

        largeDFS(node->left);
        largeDFS(node->right);

        largeSumCounts[currSum]--;
        if (!largeSumCounts[currSum])
            largeSumCounts.erase(currSum);
        currSum -= static_cast<BigSum>(currData);
    };

    // Start the large number DFS from the current node
    largeDFS(node);
}
