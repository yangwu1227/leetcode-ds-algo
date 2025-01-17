// max_ancestor_diff.hpp
#ifndef MAX_ANCESTOR_DIFF_HPP
#define MAX_ANCESTOR_DIFF_HPP
#include "tree_node.hpp"

class Solution
{
public:
    /**
     * @brief Perform a depth-first search to calculate the maximum difference between ancestor and descendant nodes in a binary tree.
     *
     * @param currentMax The maximum value encountered along the current path.
     * @param currentMin The minimum value encountered along the current path.
     * @param node A unique pointer to the current node being processed.
     *
     * @return int The maximum difference between ancestor and descendant nodes along the current path.
     */
    static int depthFirstSearch(int currentMax, int currentMin, TreeNode::ptr &node);

    /**
     * @brief Compute the maximum value `v` such that there exist different nodes `a` and `b`
     * where `v = |a.val - b.val|` and `a` is an ancestor of `b`.
     *
     * @param root A unique pointer to the root node of the tree.
     *
     * @return int The maximum difference `v` between the values of ancestor and descendant nodes.
     */
    static int maxAncestorDiff(TreeNode::ptr &root);
};

#endif
