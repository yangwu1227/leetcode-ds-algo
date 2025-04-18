// range_sum.hpp
#ifndef RANGE_SUM_HPP
#define RANGE_SUM_HPP
#include "tree_node.hpp"

class RangeSum
{
public:
    /**
     * @brief Construct a new Range Sum instance.
     *
     * @param root A unique pointer to the root of the binary search tree.
     * @param low The lower bound of the range (inclusive).
     * @param high The upper bound of the range (inclusive).
     */
    RangeSum(TreeNode::ptr &root, int low, int high);

    /**
     * @brief Calculate the range sum using an iterative breadth-first search approach.
     *
     * @return int The sum of all node values within the specified range in the subtree.
     */
    int iterative();

    /**
     * @brief Calculate the range sum using a recursive depth-first search approach.
     *
     * @return int The sum of all node values within the specified range in the subtree.
     */
    int resursive();

private:
    TreeNode::ptr root; // A unique pointer to the root of the binary search tree
    int low;            // The lower bound of the range (inclusive)
    int high;           // The upper bound of the range (inclusive)

    /**
     * @brief Helper private member for depth first search.
     *
     * @param node A unique pointer to the current node being processed.
     * @param currSum The accumulated sum so far.
     *
     * @return int
     */
    int depthFirstSearch(TreeNode::ptr &node, int currSum);
};

#endif
