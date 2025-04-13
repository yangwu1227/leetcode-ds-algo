// level_order_traversal.hpp
#ifndef LEVEL_ORDER_TRAVERSAL_HPP
#define LEVEL_ORDER_TRAVERSAL_HPP
#include "tree_node.hpp"
#include <vector>

/**
 * @brief Perform a level-order traversal (breadth-first search) on a binary tree.
 *
 * @param root A unique pointer to the root node of the binary tree
 *
 * @return std::vector<std::vector<TreeNode::datatype>> A vector of vectors, where each inner
 * vectors contains the data of nodes at the same level in the tree
 */
std::vector<std::vector<TreeNode::datatype>> levelOrderTraversal(TreeNode::ptr &root);

#endif
