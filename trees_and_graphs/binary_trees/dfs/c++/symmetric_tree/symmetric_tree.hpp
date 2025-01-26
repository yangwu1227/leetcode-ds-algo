// symmetric_tree.hpp
#ifndef SYMMETRIC_TREE_HPP
#define SYMMETRIC_TREE_HPP
#include "tree_node.hpp"

class SymmetricTree
{
public:
    /**
     * @brief Perform a depth-first search to compare two nodes for symmetry.
     *
     * @param node1 A unique pointer to the first node to compare
     * @param node2 A unique pointer to the second node to compare
     *
     * @return bool `true` if the nodes at the current recusion depth matches, otherwise `false`
     */
    static bool depthFirstSearch(TreeNode::ptr &node1, TreeNode::ptr &node2);

    /**
     * @brief
     *
     * @param root
     *
     * @return bool `true` if the tree is symmetric
     */
    static bool check(TreeNode::ptr &root);
};

#endif
