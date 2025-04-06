// deepest_leaves_sum.cpp
#include "deepest_leaves_sum.hpp"
#include "tree_node.hpp"
#include <deque>
#include <variant>   // std::holds_alternative
#include <stdexcept> // std::invalid_argument

int deepestLeavesSum(TreeNode::ptr &root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return std::get<int>(root->data);

    std::deque<TreeNode *> queue = {root.get()};
    int sumCurrLevel = 0;

    while (!queue.empty())
    {
        int numCurrNodesLevel = queue.size();
        sumCurrLevel = 0;

        for (size_t i = 0; i < numCurrNodesLevel; ++i)
        {
            TreeNode *currNode = queue.front();
            queue.pop_front();

            if (std::holds_alternative<int>(currNode->data))
            {
                sumCurrLevel += std::get<int>(currNode->data);
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
    }
    return sumCurrLevel;
}
