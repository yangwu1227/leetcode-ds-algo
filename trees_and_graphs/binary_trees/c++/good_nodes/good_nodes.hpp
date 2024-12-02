// good_nodes.hpp
#ifndef GOOD_NODES_HPP
#define GOOD_NODES_HPP
#include "tree_node.hpp"

class Solution
{
public:
    /**
     * @brief Perform a postorder traversal to count 'good' nodes in a binary tree.
     *
     * A 'good' node is defined as a node whose value is greater than or equal
     * to the maximum value encountered on the path from the root to that node.
     *
     * @param node A unique pointer to the current node being traversed in the tree
     * @param maxValSoFar The maximum value encountered from the root to this node
     * @return int The total number of 'good' nodes encountered in the subtree rooted at 'node'
     */
    static int depthFirstSearch(TreeNode::ptr &node, const int maxValSoFar);

    /**
     * @brief Count the number of 'good' nodes in the binary tree rooted at 'root'.
     *
     * @param root A unique pointer to the root node of the binary tree
     * @return int Total number of 'good' nodes in the binary tree
     */
    static int goodNodes(TreeNode::ptr &root);
};

#endif
