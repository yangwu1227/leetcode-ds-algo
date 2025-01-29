// path_sum_iii.hpp
#ifndef PATH_SUM_III_HPP
#define PATH_SUM_III_HPP
#include "tree_node.hpp"

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

#endif
