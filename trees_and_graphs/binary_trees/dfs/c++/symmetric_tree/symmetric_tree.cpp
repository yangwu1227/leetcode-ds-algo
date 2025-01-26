// symmetric_tree.cpp
#include "symmetric_tree.hpp"
#include "tree_node.hpp"

bool SymmetricTree::depthFirstSearch(TreeNode::ptr &node1, TreeNode::ptr &node2)
{
    // If both nodes are nullptrs, they are considered the same
    if (!node1 && !node2)
    {
        return true;
    }

    // If only one is nullptr, then there is a mismatch at this recrusion depth
    if (!node1 || !node2)
    {
        return false;
    }

    // If the above conditions are not met, then check if the values are the same
    if (node1->data != node2->data)
    {
        return false;
    }

    // Results of left and right sides down
    bool leftSide = SymmetricTree::depthFirstSearch(node1->left, node2->right);
    bool rightSide = SymmetricTree::depthFirstSearch(node1->right, node2->left);

    return leftSide && rightSide;
}

bool SymmetricTree::check(TreeNode::ptr &root)
{
    if (!root)
        return false;
    return SymmetricTree::depthFirstSearch(root, root);
}
