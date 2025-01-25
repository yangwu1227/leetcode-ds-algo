// invert_tree.hpp
#ifndef INVERT_TREE_HPP
#define INVERT_TREE_HPP
#include "tree_node.hpp"

/**
 * @brief A class that implements binary tree inversion.
 */
class InvertTree
{
public:
    /**
     * @brief Performs a pre-order depth-first traversal to invert the binary tree.
     *
     * @param node A unique pointer to the root node of the binary tree or subtree.
     * @return TreeNode::ptr A unique pointer to the root node of the inverted binary tree or subtree.
     */
    static void depthFirstSearch(TreeNode::ptr &node);

    /**
     * @brief Inverts a binary tree by swapping left and right subtrees recursively.
     *
     * @param root A unique pointer to the root node of the binary tree.
     */
    static void invert(TreeNode::ptr &root);
};

#endif
