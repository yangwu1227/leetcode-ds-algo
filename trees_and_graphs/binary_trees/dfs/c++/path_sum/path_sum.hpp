// path_sum.hpp
#ifndef PATH_SUM_HPP
#define PATH_SUM_HPP
#include "tree_node.hpp"

/**
 * @class Implements an algorithm that searches for a root-to-leaf path in the
 * binary tree with a specified sum.
 */
class PathSum
{
public:
    /**
     * @brief Recursively checks if a path from the `node` to any leaf node sums to the target.
     *
     * @param node A constant reference to the unique pointer to the current node in the binary tree.
     * @param currSum The cumulative sum of the nodes' values from the root to the current node.
     * @param target The target sum to check for a path from root to leaf.
     *
     * @return bool `true` if a path from root to a leaf node with a cumulative sum equal to `target`
     * exists; `false` otherwise.
     */
    static bool depthFirstSearch(TreeNode::ptr &node, int currSum, int target);

    /**
     * @brief Initiates a search for a root-to-leaf path in the binary tree with a specified sum.
     *
     * @param root A constant reference to the unique pointer to the root node of the binary tree.
     * @param target The target sum to check for a path from root to leaf.
     *
     * @return bool `true` if a path from root to any leaf node exists such that the sum of node
     * values `target` exists; `false` otherwise.
     */
    static bool searchPath(TreeNode::ptr &root, int target);
};

#endif
