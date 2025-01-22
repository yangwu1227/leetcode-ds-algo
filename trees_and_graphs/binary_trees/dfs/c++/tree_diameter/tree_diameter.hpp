// tree_diameter.hpp
#ifndef TREE_DIAMETER_HPP
#define TREE_DIAMETER_HPP
#include "tree_node.hpp"

class TreeDiameterCalculator
{
public:
    /**
     * @brief Construct a new Tree Diameter Calculator instance.
     */
    explicit TreeDiameterCalculator();

    /**
     * @brief Calculate the diameter of a binary tree.
     *
     * @param root A unique pointer to the root node of the binary tree
     * @return int The diameter of the binary tree, defined as the longest path between any two nodes
     */
    int findDiameter(TreeNode::ptr &root);

private:
    int diameter; // The maximum diameter found during the depth-first search traversal

    /**
     * @brief Perform a depth-first search to calculate the height of subtrees and update the diameter.
     *
     * @param node A unique pointer to the current node in the binary tree
     * @return int The height of the subtree rooted at the given node
     */
    int depthFirstSearch(TreeNode::ptr &node);
};

#endif
