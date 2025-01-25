// invert_tree.cpp
#include "invert_tree.hpp"
#include "tree_node.hpp"
#include <algorithm> // For std::swap

void InvertTree::depthFirstSearch(TreeNode::ptr &node)
{
    // Return nullptr
    if (!node)
        return;

    // Pre-order traversal handles logic before recursion
    std::swap(node->left, node->right);

    // Resursively swap left and rigth subtrees
    InvertTree::depthFirstSearch(node->left);
    InvertTree::depthFirstSearch(node->right);
}

void InvertTree::invert(TreeNode::ptr &root)
{
    InvertTree::depthFirstSearch(root);
}
