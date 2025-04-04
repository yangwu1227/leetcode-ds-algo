// right_size_view.hpp
#ifndef RIGHT_SIZE_VIEW_HPP
#define RIGHT_SIZE_VIEW_HPP
#include <vector>
#include "tree_node.hpp"

/**
 * @brief Find the rightmost node's value at each level of a binary tree.
 *
 * @param root A unique pointer to the root node of the binary tree.
 *
 * @return std::vector<TreeNode::datatype> A vector containing the values of the rightmost node at each level of the tree.
 */
std::vector<TreeNode::datatype> rightSide(TreeNode::ptr &root);

#endif
