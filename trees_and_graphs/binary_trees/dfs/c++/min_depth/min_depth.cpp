// min_depth.cpp
#include "min_depth.hpp"
#include "tree_node.hpp"
#include <optional>
#include <algorithm>

int minDepth(TreeNode::ptr &root)
{
    // Base case if root is nullptr
    if (!root)
    {
        return 0;
    }

    // Use std::optional to handle null child nodes
    std::optional<int> leftDepth = root->left ? std::optional<int>{minDepth(root->left)} : std::nullopt;
    std::optional<int> rightDepth = root->right ? std::optional<int>{minDepth(root->right)} : std::nullopt;

    // If one child is nullptr, return the depth of the non-null child + 1
    if (!leftDepth.has_value())
    {
        return rightDepth.value_or(0) + 1;
    }
    if (!rightDepth.has_value())
    {
        return leftDepth.value_or(0) + 1;
    }

    // Both children exist, return minimum depth + 1
    return std::min(leftDepth.value(), rightDepth.value()) + 1;
}
