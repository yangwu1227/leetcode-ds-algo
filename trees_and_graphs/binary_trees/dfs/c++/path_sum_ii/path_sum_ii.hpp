// path_sum_ii.hpp
#ifndef PATH_SUM_II_HPP
#define PATH_SUM_II_HPP
#include "tree_node.hpp"
#include <vector>

/**
 * @brief Finds all paths in the binary tree where the sum of node values equals the target sum.
 *
 * @param root A unique pointer to the root node of the binary tree
 * @param target The target sum to match
 *
 * @return std::vector<std::vector<int>> A vector of vectors representing all valid paths
 */
std::vector<std::vector<int>> pathSum(TreeNode::ptr &root, int target);

#endif
