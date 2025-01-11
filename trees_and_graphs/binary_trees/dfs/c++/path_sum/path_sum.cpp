// path_sum.cpp
#include "path_sum.hpp"
#include "tree_node.hpp"
#include <stdexcept>

bool PathSum::depthFirstSearch(TreeNode::ptr &node, int currSum, int target)
{
    // If the current node is a nullptr, return false
    if (node == nullptr)
    {
        return false;
    }
    // If the current node is a leaf node, compare it with the target
    int currData;
    if (std::holds_alternative<int>(node->data))
    {
        currData = std::get<int>(node->data);
    }
    else
    {
        throw std::runtime_error("Non-integer data encountered in TreeNode");
    }
    if (node->left == nullptr && node->right == nullptr)
    {
        // Use std::get to obtain a reference to the integer data
        return (currData + currSum) == target;
    }
    // If not a leaf node, add the current data to the cumulative sum
    currSum += currData;
    bool leftResult = PathSum::depthFirstSearch(node->left, currSum, target);
    bool rightResult = PathSum::depthFirstSearch(node->right, currSum, target);
    return leftResult || rightResult;
}

bool PathSum::searchPath(TreeNode::ptr &root, int target)
{
    return PathSum::depthFirstSearch(root, 0, target);
}
