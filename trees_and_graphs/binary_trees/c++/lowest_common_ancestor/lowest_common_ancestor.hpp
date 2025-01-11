// lowest_common_ancestor.hpp
#ifndef LOWEST_COMMON_ANCESTOR_HPP
#define LOWEST_COMMON_ANCESTOR_HPP
#include "tree_node.hpp"

/**
 * @brief Find the lowest common ancestor of two nodes in a binary tree.
 *
 * @param p A raw pointer to the first target node
 * @param q A raw pointer to the second target node
 * @param root A reference to the unique pointer to the root node
 * @return TreeNode::ptr The lowest common ancestor of nodes `p` and `q`, or `nullptr` if not found
 */
TreeNode *lowestCommonAncestor(const TreeNode *p, const TreeNode *q, const TreeNode::ptr &root);

#endif
