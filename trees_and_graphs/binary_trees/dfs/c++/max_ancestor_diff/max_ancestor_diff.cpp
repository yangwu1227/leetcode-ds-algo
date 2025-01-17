// max_ancestor_diff.cpp
#include "max_ancestor_diff.hpp"
#include "tree_node.hpp"
#include <cmath>     // std::abs
#include <variant>   // std::holds_alternative
#include <algorithm> // std::min, std::max
#include <stdexcept> // std::invalid_argument
#include <limits>    // std::numeric_limits

int Solution::depthFirstSearch(int currentMax, int currentMin, TreeNode::ptr &node)
{
    // If a leaf, return the absolute value of the difference vetween the max and min encountered so far
    if (!node)
    {
        return std::abs(currentMax - currentMin);
    }

    // Update the min and max if the current node data is larger or smaller
    int updatedMax, updatedMin;
    if (std::holds_alternative<int>(node->data))
    {
        int data = std::get<int>(node->data);
        updatedMax = std::max(currentMax, data);
        updatedMin = std::min(currentMin, data);
    }
    else
    {
        throw std::invalid_argument("TreeNode data should be int for this algorithm");
    }

    // Find the max differences for the left and right subtrees
    int leftMaxDiff = Solution::depthFirstSearch(updatedMax, updatedMin, node->left);
    int rightMaxDiff = Solution::depthFirstSearch(updatedMax, updatedMin, node->right);

    // Return the largest max differences between the left and rigth subtrees
    return std::max(leftMaxDiff, rightMaxDiff);
}

int Solution::maxAncestorDiff(TreeNode::ptr &root)
{
    // This is needed only if root can be a nullptr
    if (!root)
    {
        return 0;
    }
    int currentMax = std::numeric_limits<int>::min();
    int currentMin = std::numeric_limits<int>::max();
    return Solution::depthFirstSearch(currentMax, currentMin, root);
}
