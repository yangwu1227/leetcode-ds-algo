// path_sum_iii.hpp
#ifndef PATH_SUM_III_HPP
#define PATH_SUM_III_HPP
#include "tree_node.hpp"
#include <cstdint>

/**
 * @brief Finds the number of paths in a binary tree where the sum of node values equals a given target.
 * All node values are assumed to be within the range of the int type.
 *
 * @param root A unique pointer to the root node of the binary tree
 * @param target The target sum to find in paths
 *
 * @return int The number of valid paths found
 */
int pathSum(TreeNode::ptr &root, int target);

/**
 * @brief Helper for paths that involve large numbers using 64-bit arithmetic.
 *
 * @param initialSum The initial sum that resulted in integer overflow for `int`
 * @param node A unique pointer to the current node
 * @param count The count of total valid paths found thus far
 * @param target The target sum to find in paths
 */
void handleLargePath(std::int64_t initialSum, TreeNode::ptr &node, int &count, const int target);

#endif
