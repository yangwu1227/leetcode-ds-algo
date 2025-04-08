// zig_zag.hpp
#ifndef ZIG_ZAG_HPP
#define ZIG_ZAG_HPP
#include "tree_node.hpp"
#include <vector>
#include <deque>

/**
 * @brief Perform a zig-zag (spiral) level order traversal of a binary tree.
 *
 * In zig-zag traversal, the traversal alternates between left-to-right and
 * right-to-left order at each level of the tree.
 *
 * @param root A unique pointer to the root node of the binary tree.
 *
 * @return std::vector<std::deque<TreeNode::datatype>> A list where each element is a deque containing the node data for one level.
 * The nodes at even-indexed levels are ordered left-to-right, while nodes at odd-indexed levels are ordered right-to-left.
 */
std::vector<std::vector<TreeNode::datatype>> zigZag(TreeNode::ptr &root);

#endif
