// level_averages.cpp
#include "level_averages.hpp"
#include "tree_node.hpp"
#include <vector>
#include <variant>
#include <deque>

std::vector<double> computeLevelAverages(TreeNode::ptr &root)
{
    if (root == nullptr)
        return {};
    if (root->left == nullptr && root->right == nullptr)
    {
        int nodeData = std::get<int>(root->data);
        return {static_cast<double>(nodeData)};
    }

    std::deque<TreeNode *> queue = {root.get()};
    std::vector<double> output;

    while (!queue.empty())
    {
        const size_t numNodesCurrLevel = queue.size();
        long long int runningLevelSum = 0;

        for (size_t i = 0; i < numNodesCurrLevel; i++)
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

        output.push_back(static_cast<double>(runningLevelSum) / static_cast<double>(numNodesCurrLevel));
    }

    return output;
}
