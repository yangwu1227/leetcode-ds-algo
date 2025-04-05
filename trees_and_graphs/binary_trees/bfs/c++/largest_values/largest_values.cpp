// largest_values.cpp
#include "largest_values.hpp"
#include "tree_node.hpp"
#include <vector>
#include <deque>     // std::deque
#include <limits>    // std::numerical_limits
#include <algorithm> // std::max
#include <variant>   // std::holds_alternative
#include <stdexcept> // std::invalid_argument

std::vector<int> largestValues(TreeNode::ptr &root)
{
    if (root == nullptr)
        return {};

    std::deque<TreeNode *> queue = {root.get()};
    std::vector<int> largestVals = {};
    int maxCurrLevel;

    while (!queue.empty())
    {
        int numNodesCurrLevel = queue.size();
        maxCurrLevel = std::numeric_limits<int>::min();

        for (size_t i = 0; i < numNodesCurrLevel; ++i)
        {
            TreeNode *currNode = queue.front();
            queue.pop_front();

            if (std::holds_alternative<int>(currNode->data))
            {
                int currData = std::get<int>(currNode->data);
                maxCurrLevel = std::max(maxCurrLevel, currData);
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
        largestVals.push_back(maxCurrLevel);
    }
    return largestVals;
}
