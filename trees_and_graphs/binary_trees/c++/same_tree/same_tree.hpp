// same_tree.hpp
#ifndef SAME_TREE_HPP
#define SAME_TREE_HPP
#include "tree_node.hpp"

class Solution
{
public:
    /**
     * @brief Recursively compares two binary tree nodes to determine if they are the same.
     *
     * @param left A unqiue pointer to a TreeNode instance
     * @param right A unique pointer to a TreeNode instance
     * @return bool true if the two nodes (and their subtrees) are identical, otherwise false
     */
    static bool depthFirstSearch(TreeNode::ptr &left, TreeNode::ptr &right);

    /**
     * @brief Determines whether two binary trees are the same.
     *
     * @param firstTree A unique poitner to the first TreeNode instance
     * @param secondTree A unique poitner to the second TreeNode instance
     * @return bool true if the two trees are identical, otherwise false
     */
    static bool sameTree(TreeNode::ptr &firstTree, TreeNode::ptr &secondTree);
};

#endif
