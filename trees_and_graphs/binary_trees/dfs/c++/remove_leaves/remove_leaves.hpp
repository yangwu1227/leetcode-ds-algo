// remove_leaves.hpp
#ifndef REMOVE_LEAVES_HPP
#define REMOVE_LEAVES_HPP
#include "tree_node.hpp"

/**
 * @brief Prune the binary tree by removing all leaves with the target value.
 *
 * @param root A unique pointer to the root of the binary tree
 * @param target The target value to identify and remove leaf nodes
 *
 * @return TreeNode::ptr A unique pointer to the root node of the modified binary tree; nullptr if all nodes are removed
 */
TreeNode::ptr removeLeaves(TreeNode::ptr &root, int target);

#endif
