// largest_values.hpp
#ifndef LARGEST_VALUES_HPP
#define LARGEST_VALUES_HPP
#include "tree_node.hpp"
#include <vector>

/**
 * @brief Find the largest data in each level of a binary tree using BFS.
 *
 * @param root A unique pointer to the root of the binary tree
 *
 * @return std::vector<int> Vector of maximum values for each level of the tree
 */
std::vector<int> largestValues(TreeNode::ptr &root);

#endif
