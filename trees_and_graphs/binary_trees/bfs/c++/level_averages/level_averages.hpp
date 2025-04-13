// level_averages.hpp
#ifndef LEVEL_AVERAGES_HPP
#define LEVEL_AVERAGES_HPP
#include "tree_node.hpp"
#include <vector>

/**
 * @brief Given the root of a binary tree, return the average value of the nodes on each level
 * as an array.
 *
 * @param root A unique pointer to the root node of the binary tree
 *
 * @return std::vector<double> A vector of level averages
 */
std::vector<double> computeLevelAverages(TreeNode::ptr &root);

#endif
