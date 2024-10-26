// max_depth.cpp
#include "max_depth.hpp"
#include "tree_node.hpp"

int maxDepth(const TreeNode::ptr &root)
{
    // Return 0 if the node has no children
    if (root == nullptr)
    {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return std::max(leftDepth, rightDepth) + 1;
}
