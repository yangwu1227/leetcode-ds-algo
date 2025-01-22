// tree_diameter.cpp
#include "tree_diameter.hpp"
#include "tree_node.hpp"
#include <algorithm> // std::max
#include <stdexcept> // std::runtime_error

TreeDiameterCalculator::TreeDiameterCalculator() : diameter(0) {}

int TreeDiameterCalculator::depthFirstSearch(TreeNode::ptr &node)
{
    // If nullptr, return zero for the height
    if (!node)
    {
        return 0;
    }

    // Find the heights of the left and right subtrees
    int leftSubtreeHeight = TreeDiameterCalculator::depthFirstSearch(node->left);
    int rightSubtreeHeight = TreeDiameterCalculator::depthFirstSearch(node->right);

    // Update the diameter if a larger value is found
    this->diameter = std::max(this->diameter, leftSubtreeHeight + rightSubtreeHeight);

    // Return the height of the tallest tree rooted at this node
    return std::max(leftSubtreeHeight, rightSubtreeHeight) + 1;
}

int TreeDiameterCalculator::findDiameter(TreeNode::ptr &root)
{
    // If the diameter member is non-zero, raise an error
    if (this->diameter > 0)
    {
        throw std::runtime_error("This instance has already processed a tree; please create a new instance");
    }
    // Suppress warnings on unused
    [[maybe_unused]] int height = TreeDiameterCalculator::depthFirstSearch(root);
    return this->diameter;
}
