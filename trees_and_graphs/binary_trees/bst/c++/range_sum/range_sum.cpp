// range_sum.cpp
#include "range_sum.hpp"
#include "tree_node.hpp"
#include <variant>
#include <deque>

RangeSum::RangeSum(TreeNode::ptr &root, int low, int high) : root(std::move(root)), low(low), high(high) {};

int RangeSum::iterative()
{
    // Handle empty tree or single node tree cases
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
    {
        if (std::holds_alternative<int>(root->data))
        {
            int data = std::get<int>(root->data);
            return (data >= low && data <= high) ? data : 0;
        }
    }

    std::deque<TreeNode *> queue = {root.get()};
    int rangeSum = 0;

    while (!queue.empty())
    {
        TreeNode *currNode = queue.front();
        int currData;
        if (std::holds_alternative<int>(root->data))
        {
            currData = std::get<int>(currNode->data);
        }
        else
        {
            throw std::invalid_argument("TreeNode data should be int for this algorithm");
        }
        queue.pop_front();

        // Add to sum if current data is within the range
        if (currData >= low && currData <= high)
            rangeSum += currData;
        // If left node is not nullptr, and current data is greater than low, we may explore left substree, so enque
        if (currNode->left && currData > low)
            queue.push_back(currNode->left.get());
        // If right node is not nullptr, and current data is less than high, we may explore right substree, so enque
        if (currNode->right && currData < high)
            queue.push_back(currNode->right.get());
    }

    return rangeSum;
}

int RangeSum::depthFirstSearch(TreeNode::ptr &node, int currSum)
{
    // If nullptr, return 0 so we add nothing to the cumulative sum
    if (node == nullptr)
        return 0;

    int cumulativeSum = 0;
    int currData;
    if (std::holds_alternative<int>(node->data))
        currData = std::get<int>(node->data);

    // Add to sum if current data is within the range
    if (currData >= low && currData <= high)
        cumulativeSum += currData;
    // If current data is greater than low, we may explore left substree
    if (currData > low)
        cumulativeSum += depthFirstSearch(node->left, cumulativeSum);
    // If current data is less than high, we may explore right substree
    if (currData < high)
        cumulativeSum += depthFirstSearch(node->right, cumulativeSum);

    return cumulativeSum;
}

int RangeSum::resursive()
{
    // Handle empty tree or single node tree cases
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
    {
        if (std::holds_alternative<int>(root->data))
        {
            int data = std::get<int>(root->data);
            return (data >= low && data <= high) ? data : 0;
        }
    }

    return depthFirstSearch(root, 0);
}
