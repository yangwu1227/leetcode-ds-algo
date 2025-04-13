// max_level_sum.cpp
#include "max_level_sum.hpp"
#include "tree_node.hpp"
#include <deque>
#include <variant>   // std::hold_alternative
#include <limits>    // std::numeric_limits
#include <stdexcept> // std::invalid_argument

int maxLevelSum(TreeNode::ptr &root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 1;

    std::deque<TreeNode *> queue = {root.get()};
    long long int maxSum = std::numeric_limits<long long int>::min();
    int currLevel = 1, maxLevel = 1;

    while (!queue.empty())
    {
        const size_t numNodesCurrLevel = queue.size();
        long long int runningLevelSum = 0;

        for (size_t i = 0; i < numNodesCurrLevel; ++i)
        {
            TreeNode *currNode = queue.front();
            queue.pop_front();

            if (std::holds_alternative<int>(currNode->data))
            {

                runningLevelSum += std::get<int>(currNode->data);
            }
            else
            {
                throw std::invalid_argument("TreeNode data should be int for this algorithm");
            }

            if (currNode->left)
                queue.push_back(currNode->left.get());
            if (currNode->right)
                queue.push_back(currNode->right.get());
        }
        maxLevel = runningLevelSum > maxSum ? currLevel : maxLevel;
        maxSum = std::max(runningLevelSum, maxSum);
        currLevel += 1;
    }
    return maxLevel;
}
